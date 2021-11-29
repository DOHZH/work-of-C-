#include "OGRMultiLineString.h"

OGRMultiLineString::OGRMultiLineString()
{
	type_index = 6;
	id = CalId(type_index);
	type = "OGRMultiLineString";
}

PointSet OGRMultiLineString::GetAllPoints() const
{
	PointSet p;
	for (int i = 0; i < container.size(); ++i)
	{
		PointSet p_imp = container[i].GetAllPoints();
		for (int j = 0; j < p_imp.size(); ++j)
		{
			p.push_back(p_imp[j]);
		}
	}
	return p;
}

double OGRMultiLineString::Getlength()
{
	double l = 0;
	for (int i = 0; i < container.size(); ++i)
		l += container[i].GetLength();
	return l;
}

bool OGRMultiLineString::IsEmpty() const
{
	return container.empty();
}

void OGRMultiLineString::GetMBR(OGREnvelope* e) const
{
	if (IsEmpty())
	{
		throw  "�㼯��" + std::to_string(id) + "Ϊ�ռ�\n";
	}
	PointSet p = GetAllPoints();
	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < p.size(); ++i)
	{
		double x = p[i].x;
		double y = p[i].y;
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

OGREnvelope OGRMultiLineString::GetMBR() const
{
	if (IsEmpty())
	{
		throw  "�㼯��" + std::to_string(id) + "Ϊ�ռ�\n";
	}
	PointSet p = GetAllPoints();
	double minx = DBL_MAX, maxx = DBL_MIN, miny = DBL_MAX, maxy = DBL_MIN;
	for (int i = 0; i < p.size(); ++i)
	{
		double x = p[i].x;
		double y = p[i].y;
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

OGRMultiLineString* OGRMultiLineString::Clone()
{
	OGRMultiLineString l;
	l.container = container;

	OGRMultiLineString* result = &l;
	return result;
}

void OGRMultiLineString::Clone(OGRMultiLineString* l)
{
	container = l->container;
}

OGRErr OGRMultiLineString::ImportFromWkt(std::string)
{
	std::cout << "�߶μ���û�ж��ļ�������\n";
	return OGRErr::ReadErr;
}

OGRErr OGRMultiLineString::ExportToWkt(std::string) const
{
	std::cout << "�߶μ���û��д�ļ�������\n";
	return OGRErr::OutErr;
}

void OGRMultiLineString::AddGeometry(OGRLineString l)
{
	container.push_back(l);
}

void OGRMultiLineString::RemoveGeometry(int index)
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "û���ҵ���ӦԪ��";
	}
	else
	{
		container.erase(container.begin() + index);
	}
}

OGRGeometry* OGRMultiLineString::GetGeometry(int index) const
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "û���ҵ���ӦԪ��";
		return nullptr;
	}
	else
	{
		OGRLineString p = container[index];
		OGRLineString* result = &p;
		return result;
	}
}

void OGRMultiLineString::UpdateGeometry(int index, OGRLineString l)
{
	if (index > container.size() - 1 || index < 0)
	{
		std::cout << "û���ҵ���ӦԪ��";
	}
	else
	{
		container[index] = l;
	}
}


int OGRMultiLineString::GetNumGeometries() const
{
	return container.size();
}
