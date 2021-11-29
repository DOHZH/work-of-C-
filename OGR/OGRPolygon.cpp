#include "OGRPolygon.h"
#include "OGRLineString.h"

OGRPolygon::OGRPolygon()
{
    type_index = 2;
    id = CalId(type_index);
    type = "OGRPolygon";
}

OGRPolygon::OGRPolygon(PointSet p, std::vector<int>* index_signal)
{
	type_index = 2;
	id = CalId(type_index);
	type = "OGRPolygon";
	container = p;
	if (index_signal == nullptr)
		hole_index.push_back(container.size());
	else
	{
		hole_index = *index_signal;
	}
}


bool OGRPolygon::IsEmpty() const
{
	if (container.empty())
		return true;

	return false;
}

void OGRPolygon::GetMBR(OGREnvelope* e) const
{
	//����ֻ�ü�����Ϊ0��PointSet����Ϊ����Ȧ�ķ�Χ���
	if (IsEmpty())
	{
		std::cout << "����" << id << "Ϊ�ռ�\n";
		return;
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	for (int i = 0; i < hole_index[0]; ++i)
	{
		double x = container[i].x;
		double y = container[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	e->max_x = maxx;
	e->min_x = minx;
	e->max_y = maxy;
	e->min_y = miny;
}

OGREnvelope OGRPolygon::GetMBR() const
{
	if (IsEmpty())
	{
		throw  "��" + std::to_string(id) + "Ϊ�ռ�\n";
	}

	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;

	for (int i = 0; i < container.size(); ++i)
	{
		double x = container[i].x;
		double y = container[i].y;
		if (x < minx)
			minx = x;

		if (x > maxx)
			maxx = x;

		if (y < miny)
			miny = y;

		if (y > maxy)
			maxy = y;
	}

	OGREnvelope e;
	e.max_x = maxx;
	e.min_x = minx;
	e.max_y = maxy;
	e.min_y = miny;
	return e;
}

void OGRPolygon::Clone(OGRPolygon* geo)
{
	container = geo->container;
	hole_index = geo->hole_index;
	area = geo->area;
	perimeter = geo->perimeter;
}

OGRPolygon* OGRPolygon::Clone()
{
	OGRPolygon p;
	p.container = container;
	p.hole_index = hole_index;
	p.area = area;
	p.perimeter = perimeter;

	OGRPolygon* result = &p;
	return result;
}

OGRErr OGRPolygon::ImportFromWkt(std::string path)
{
	std::ifstream myfile;
	myfile.open(path);
	if (!myfile.is_open())
	{
		throw "·������" + path + "������";
		return OGRErr::ReadErr;
	}
	std::string temp = "";

	while (std::getline(myfile, temp))
	{
		temp = trim(temp);
		std::string sub = "Polygon ";//��Ҫɾ�����Ӵ�����
		DeleteSub(temp, sub, sub.size());

		std::stack<char> signal_stack;
		std::stack<char> num_stack;
		Point p;
		PointSet p_set;
		std::string num_str = "";//���ֵ��ַ���ʽ

		container.clear();
		hole_index.clear();
		for (int i = 0; i < temp.size(); ++i)
		{
			if (temp[i] == '(')
			{
				signal_stack.push(temp[i]);
				continue;
			}
			else if (temp[i] == ')')
			{
				while (signal_stack.top() != '(')
				{
					num_stack.push(signal_stack.top());
					signal_stack.pop();
				}
				signal_stack.pop();

				while (!num_stack.empty())
				{
					num_str.push_back(num_stack.top());
					num_stack.pop();
				}

				if (num_str != "")
				{
					std::vector<std::string> temp_divide = DivideStr(num_str, ',');
					if (temp_divide.size() < 3)
					{
						myfile.close();
						throw "�ļ�" + path + "��Ϣ����";
						return OGRErr::ReadErr;
					}
					hole_index.push_back(temp_divide.size());
					for (int j = 0; j < temp_divide.size(); ++j)
					{
						std::vector<std::string> temp2_divide = DivideStr(temp_divide[j], ' ');
						if (temp2_divide.size() != 2)
						{
							myfile.close();
							throw "�ļ�" + path + "��Ϣ����";
							return OGRErr::ReadErr;
						}
						Fresult x_fin = StringToFloat(temp2_divide[0]), y_fin = StringToFloat(temp2_divide[1]);
						if (x_fin.str_status && y_fin.str_status)
						{
							Point p = { x_fin.result, y_fin.result, true };
							container.push_back(p);
						}
						else
						{
							myfile.close();
							throw "ת��ʧ�ܣ�" + path + "�ļ��е�������ڴ���";
							return OGRErr::ReadErr;
						}
					}

					num_str = "";
				}

				if (temp[i + 1] == ',')
					i += 1;
			}
			else
			{
				signal_stack.push(temp[i]);
			}
		}
		
		
		if (!container.empty() && !hole_index.empty()) {

			std::vector<OGRPolygon> poly_container;
			for (int j = 0; j < hole_index.size(); ++j)
			{
				PointSet p_0;
				for (int i = 0; i < hole_index[0]; ++i)
				{
					p_0.push_back(container[i]);
				}
				OGRPolygon poly_1(p_0);
				poly_container.push_back(poly_1);
			}

			if (!CheckConcave())
			{
				std::cout << "����β���͹�����";
				container.clear();
				hole_index.clear();
				myfile.close();
				throw "�����ļ�" + path + "����β���͹�����";
				return OGRErr::ReadErr;
			}

			if (!CheckRing(poly_container, 0))
			{
				myfile.close();
				throw "�����ļ�" + path + "����β���͹�����";
				return OGRErr::ReadErr;
			}
			CalPerimeter();
			CalArea();
			myfile.close();
			return OGRErr::ReadTrue;
		}
	}

	myfile.close();
	throw "�����ļ�" + path + "�ǿ��ļ�";
	return OGRErr::ReadErr;
}

OGRErr OGRPolygon::ExportToWkt(std::string path) const
{
	std::ofstream outfile;
	outfile.open(path, std::ios::trunc | std::ios::out);
	int index = 0;//��¼��ǰ�ǵڼ�����

	if (!IsEmpty())
	{	
		std::string result = "Polygon (";
		for (int i = 0; i < hole_index.size(); ++i)
		{
			int amount = hole_index[i];
			result += "(";
			int stop = index + amount;//����ͼ�εĽ�ֹ���
			for (index; index < stop; ++index)
			{
				PrtintPoint(result, container[index]);
				if (index < stop - 1)
					result += ",";
			}

			if (i == hole_index.size() - 1)
				result += ")";
			else
			{
				result += "),";
			}
		}
		result += ")";

		outfile << result;

		outfile.close();
		return OGRErr::OutTrue;
	}
	else
	{
		throw type + std::to_string(id) + "�㼯Ϊ��";
		outfile.close();
		return OGRErr::OutErr;
	}
	
}

double OGRPolygon::GetArea()
{
	double result = 0;
	for (int i = 0; i < area.size(); ++i)
		result += area[i];
	return result;
}

double OGRPolygon::GetPerimeter()
{
	double result = 0;
	for (int i = 0; i < perimeter.size(); ++i)
		result += perimeter[i];
	return result;
}

bool OGRPolygon::Intersects(OGRPolygon* polygon)
{
	return !IsDisjoint(polygon);
}

bool OGRPolygon::Intersects(OGRLineString* l)
{
	return !IsDisjoint(l);
}

bool OGRPolygon::Contains(OGRPoint* p)
{

	return ContainP(p->container[0]);
}

bool OGRPolygon::Contains(OGRLineString* l)
{
	for (int i = 0; i < l->container.size(); ++i)
	{
		Point p = l->container[i];
		if (!ContainP(p))
			return false;
	}
	return true;
}

bool OGRPolygon::Contains(OGRPolygon* polygon)
{
	//����ֻ�ü�����Ϊ0���ǲ��ǰ���������Ϳ���
	int end = polygon->hole_index[0]; 
	for (int i = 0; i < end; ++i)
	{
		Point p = polygon->container[i];
		if (!ContainP(p))
			return false;
	}
	return true;
}

void OGRPolygon::Clear()
{
	container.clear();
	hole_index.clear();
}

bool OGRPolygon::CheckConcave()
{
	int i, index = 0;
	Point tp = container[0];
	int vcount = hole_index[0];
	int* bc = new int[vcount];
	for (i = 1; i < vcount; i++) // Ѱ�ҵ�һ��͹���� 
	{
		if (container[i].y < tp.y || (container[i].y == tp.y && container[i].x < tp.x))
		{
			tp = container[i];
			index = i;
		}
	}
	int count = vcount - 1;
	bc[index] = 1;
	while (count) // �ж�͹���� 
	{
		if (Multiply(container[(index + 1) % vcount], container[(index + 2) % vcount], container[index]) >= 0)
			bc[(index + 1) % vcount] = 1;
		else
			bc[(index + 1) % vcount] = 0;
		index++;
		count--;
	}

	for (int i = 0; i < vcount; ++i)
		if (!bc[i])
			return false;
	return true;
}

double OGRPolygon::CalPerimeterDivide(int num)
{
	double result = 0;//������
	int start = 0;//���㿪ʼ���
	for (int i = 0; i < num; ++i)
	{
		start += hole_index[i];
	}

	int amount = hole_index[num];//��ǰ������ж��ٸ���
	for (int index = 0; index < amount; ++index)
	{
		if (index == amount - 1)
			result += CalLength(container[start + index], container[start]);
		else
		{
			result += CalLength(container[start + index], container[start + index + 1]);
		}

	}

	return result;
}

void OGRPolygon::CalPerimeter()
{
	for (int i = 0; i < hole_index.size(); ++i)
	{
		double result = CalPerimeterDivide(i);
		perimeter.push_back(result);
	}
}

void OGRPolygon::CalArea()
{
	int i = 0;
	double result = 0;
	int start = 0;
	for (int j = 0; j < hole_index.size(); ++j)
	{
		double s = 0;
		int start_o = start;
		int end = start + hole_index[j];
		for (start; start < end; ++start)
		{
			int imp = start + 1;
			if (start + 1 == end)
				imp = start_o;
			
			s += container[start].x * container[imp].y - container[imp].x * container[start].y;
		}
		area.push_back(s/2);
	}
}

bool OGRPolygon::ContainP(Point p)
{
	
	double p_x = p.x;
	double p_y = p.y;
	int num = 0;//�������
	for (int i = 0; i < hole_index[0]; ++i)
	{
		Point p1, p2;
		if (i == hole_index[0]-1) {
			p1 = container[i];
			p2 = container[0];
		}
		else
		{
			p1 = container[i];
			int i_0 = i + 1;
			p2 = container[i_0];
		}

		double slope = (p1.y - p2.y) / (p1.x - p2.x);
		bool cond1 = (p1.x <= p_x) && (p_x < p2.x);
		bool cond2 = (p2.x <= p_x) && (p_x < p1.x);
		bool above = (p_y < slope* (p_x - p1.x) + p1.y);

		if ((cond1 || cond2) && above) num++;

	}
	return (num % 2 != 0);
}

bool OGRPolygon::IsDisjoint(OGRPolygon* polygon)
{
	//����ֻ�ü�����Ϊ0���ǲ��ǰ���������Ϳ���
	int end = polygon->hole_index[0];
	for (int i = 0; i < end; ++i)
	{
		Point p = polygon->container[i];
		if (ContainP(p))
			return false;
	}
	return true;
}

bool OGRPolygon::IsDisjoint(OGRLineString* l)
{
	
	for (int i = 0; l->container.size(); ++i)
	{
		Point p = l->container[i];
		if (ContainP(p))
			return false;
	}
	return true;
}

bool OGRPolygon::CheckRing(std::vector<OGRPolygon> p, int i)
{
	OGRPolygon poly_0 = p[i];
	for (int j = 1; j < p.size() - i; ++j)
	{
		if (!poly_0.Intersects(&p[i + j]))
			return false;
	}
	if (i >= p.size() - 1)
		return true;
	else
	{
		return CheckRing(p, i + 1);
	}
}

void OGRPolygon::Update()
{
	CalPerimeter();
	CalArea();
}
