#include "extra_geo_method.h"
void Add(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "��" << index << "�д��󣬼��addָ���Ƿ����\n";
		return;
	}
	else
	{
		if (point_list.empty())
		{
			std::vector<float> point_seq_num = Convert(command[3]);
			if (point_seq_num.size() != 2)
			{
				std::cout << "��" << index << "�д����������벻�ϸ����ʧ��\n";
			}
			else
			{
				Point p(command[2], point_seq_num);
				point_list.push_back(p);
			}
			
		}
		else
		{
			//���ȼ��õ��Ƿ��Ѿ�����
			for (int i = 0; i < point_list.size(); ++i)
			{
				if (point_list[i].GetVarName() == command[2])
				{
					std::cout << "��" << index << "�д����Ѿ����ڸõ�\n";
					return;
				}
			}

			std::vector<float> point_seq_num = Convert(command[3]);
			if (point_seq_num.size() != 2)
			{
				std::cout << "��" << index << "�д����������벻�ϸ����ʧ��\n";
			}
			else
			{
				Point p(command[2], point_seq_num);
				point_list.push_back(p);
				std::cout << "��ӵ�" << command[2] << "\n";
			}
		}
	}
}

void Add(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "��" << index << "�д��󣬼��addָ���Ƿ����\n";
		return;
	}

	//���ȼ��õ��Ƿ��Ѿ�����
	for (int i = 0; i < polyline_list.size(); ++i)
	{
		if (polyline_list[i].GetVarName() == command[2])
		{
			std::cout << "��" << index << "�д����Ѿ����ڸõ�\n";
			return;
		}
	}

	std::vector<float> polyline_seq_num = Convert(command[3]);
	if (polyline_seq_num.size()%2 != 0)
	{
		std::cout << "��" << index << "�д����������벻�ϸ����ʧ��\n";
	}
	else
	{
		Polyline p(command[2], polyline_seq_num);
		polyline_list.push_back(p);
		std::cout << "�������" << command[2] << "\n";
	}
}

void Add(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 4)
	{
		std::cout << "��" << index << "�д��󣬼��addָ���Ƿ����\n";
		return;
	}

	//���ȼ��õ��Ƿ��Ѿ�����
	for (int i = 0; i < ring_list.size(); ++i)
	{
		if (ring_list[i].GetVarName() == command[2])
		{
			std::cout << "��" << index << "�д����Ѿ����ڸõ�\n";
			return;
		}
	}

	std::vector<float> ring_seq_num = Convert(command[3]);
	if (ring_seq_num.size() % 2 != 0)
	{
		std::cout << "��" << index << "�д����������벻�ϸ����ʧ��\n";
	}
	else
	{
		Ring p(command[2], ring_seq_num);
		ring_list.push_back(p);
		std::cout << "��ӻ�" << command[2] << "\n";
	}
}

void Add(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5)
	{
		std::cout << "��" << index << "�д��󣬼��addָ���Ƿ����\n";
		return;
	}

	//���ȼ��õ��Ƿ��Ѿ�����
	for (int i = 0; i < polygon_list.size(); ++i)
	{
		if (polygon_list[i].GetVarName() == command[2])
		{
			std::cout << "��" << index << "�д����Ѿ����ڸõ�\n";
			return;
		}
	}

	std::vector<float> ring_seq_num = Convert(command[4]);
	if (ring_seq_num.size() % 2 != 0)
	{
		std::cout << "��" << index << "�д����������벻�ϸ����ʧ��\n";
	}
	else
	{
		Polygon p(command[2], ring_seq_num);
		polygon_list.push_back(p);
		std::cout << "��Ӷ����" << command[2] << "\n";
	}
}

void Delete(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "��" << index << "�д��󣬼��delָ���Ƿ����\n";
		return;
	}
	else
	{
		if (point_list.empty())
		{
			std::cout << "��" << index << "�д���point��Ϊ��\n";
			return;
		}
		else
		{
			bool have_point = 0;//����״̬����Ҫ����point_list���Ƿ�������Ҫɾ���ĵ�
			for (int i = 0; i < point_list.size(); ++i)
			{
				if (point_list[i].GetVarName() == command[2])
				{
					point_list.erase(point_list.begin() + i);
					std::cout << "ɾ��point " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "��" << index << "�д��󣬱���" << command[2] << "������\n";
				return;
			}
		}
	}
}

void Delete(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "��" << index << "�д��󣬼��delָ���Ƿ����\n";
		return;
	}
	else
	{
		if (polyline_list.empty())
		{
			std::cout << "��" << index << "�д���point��Ϊ��\n";
			return;
		}
		else
		{
			bool have_point = 0;//����״̬����Ҫ����polyline_list���Ƿ�������Ҫɾ���ĵ�
			for (int i = 0; i < polyline_list.size(); ++i)
			{
				if (polyline_list[i].GetVarName() == command[2])
				{
					polyline_list.erase(polyline_list.begin() + i);
					std::cout << "ɾ��polyline " <<command[2]<<"\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "��" << index << "�д��󣬱���" << command[2] << "������\n";
				return;
			}

			
		}
	}
}

void Delete(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "��" << index << "�д��󣬼��delָ���Ƿ����\n";
		return;
	}
	else
	{
		if (ring_list.empty())
		{
			std::cout << "��" << index << "�д���point��Ϊ��\n";
			return;
		}
		else
		{
			bool have_point = 0;//����״̬����Ҫ����polyline_list���Ƿ�������Ҫɾ���ĵ�
			for (int i = 0; i < ring_list.size(); ++i)
			{
				if (ring_list[i].GetVarName() == command[2])
				{
					ring_list.erase(ring_list.begin() + i);
					std::cout << "ɾ��ring " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "��" << index << "�д��󣬱���" << command[2] << "������\n";
				return;
			}


		}
	}
}

void Delete(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 3)
	{
		std::cout << "��" << index << "�д��󣬼��delָ���Ƿ����\n";
		return;
	}
	else
	{
		if (polygon_list.empty())
		{
			std::cout << "��" << index << "�д���point��Ϊ��\n";
			return;
		}
		else
		{
			bool have_point = 0;//����״̬����Ҫ����polyline_list���Ƿ�������Ҫɾ���ĵ�
			for (int i = 0; i < polygon_list.size(); ++i)
			{
				if (polygon_list[i].GetVarName() == command[2])
				{
					polygon_list.erase(polygon_list.begin() + i);
					std::cout << "ɾ��polygon " << command[2] << "\n";
					have_point = 1;
					return;
				}
			}

			if (!have_point)
			{
				std::cout << "��" << index << "�д��󣬱���" << command[2] << "������\n";
				return;
			}


		}
	}
}

void Set(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	int point_index = 0;
	bool have_p = 0;//�����Ƿ��е㣬����б�Ϊ1
	//�ȼ���Ƿ񳤶�����
	if (command.size() != 5)
	{
		std::cout << "��" << index << "���д��������Ƿ����\n";
		return;
	}

	for (int i = 0; i < point_list.size(); ++i)
	{
		if (point_list[i].GetVarName() == command[2])
		{
			point_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "��" << index << "���д�" << command[2] << "������\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//�޸ĵ�������Ϣ
			std::vector<float> point_num = Convert(command[4]);
			if (point_num.size() != 2)
			{
				std::cout << "��" << index << "���д�" << command[4] << "�����������\n";
				return;
			}
			else
			{
				point_list[point_index].Set(point_num);
			}
		}
		else if (command[3] == "move")
		{
			//�ƶ���
			std::vector<float> move_num = Convert(command[4]);
			if (move_num.size() != 2)
			{
				std::cout << "��" << index << "���д�" << command[4] << "�����������\n";
				return;
			}
			else
			{
				point_list[point_index].Move(move_num);
			}
		}
		else if (command[3] == "name")
		{
			//��������
			point_list[point_index].Name(command[4]);
		}
		else
		{
			std::cout << "��" << index << "���д�û��" << command[3] << "ָ��\n";
			return;
		}
	}

}

void Set(std::vector <Polyline>& polyline_list, const std::vector<std::string> command, const int index)
{
	int poly_index = 0;//Ҫ�������������
	bool have_p = 0;//�����Ƿ��е㣬����б�Ϊ1

	for (int i = 0; i < polyline_list.size(); ++i)
	{
		if (polyline_list[i].GetVarName() == command[2])
		{
			poly_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "��" << index << "���д�" << command[2] << "������\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 6)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			//�޸ĵ�������Ϣ
			std::vector<float> point_num = Convert(command[5]);//�洢��������Ϣ
			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "��" << index << "���д�����" << command[5] << "�����������\n";
				return;
			}
			else
			{
				if (polyline_list[poly_index].Set(point_index, point_num))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
					return;
				}
			}
		}
		else if (command[3] == "move")
		{
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 6)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			//�ƶ���
			std::vector<float> move_num = Convert(command[5]);
			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "��" << index << "���д�" << command[5] << "�����������\n";
				return;
			}
			else
			{
				if (polyline_list[poly_index].Move(point_index, move_num))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
					return;
				}
			}
		}
		else if (command[3] == "del")
		{
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}
			//ɾ����
			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (polyline_list[poly_index].Delete(point_index))
			{
				return;
			}
			else
			{
				std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
				return;
			}
		}
		else if (command[3] == "set_length")
		{
			
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}
			//���ó���
			polyline_list[poly_index].SetLength(command[4]);
		}
		else if (command[3] == "name")
		{
			
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}
			//��������
			polyline_list[poly_index].SetName(command[4]);
		}
		else
		{
			std::cout << "��" << index << "���д�û��" << command[3] << "ָ��\n";
		}
	}
}

void Set(std::vector <Ring>& ring_list, const std::vector<std::string> command, const int index)
{
	int ring_index = 0;//Ҫ�������������
	bool have_p = 0;//�����Ƿ��е㣬����б�Ϊ1

	for (int i = 0; i < ring_list.size(); ++i)
	{
		if (ring_list[i].GetVarName() == command[2])
		{
			ring_index = i;
			have_p = 1;
			break;
		}
	}

	if (!have_p)
	{
		std::cout << "��" << index << "���д�" << command[2] << "������\n";
		return;
	}
	else
	{
		if (command[3] == "set")
		{
			//�ȼ���Ƿ񳤶�����
			if (command.size() != 6)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			//�޸ĵ�������Ϣ
			std::vector<float> point_num = Convert(command[5]);//�洢��������Ϣ
			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "��" << index << "���д�����" << command[5] << "�����������\n";
				return;
			}
			else
			{
				if (ring_list[ring_index].Set(point_index, point_num))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
					return;
				}
			}
		}
		else if (command[3] == "move")
		{
			//�ƶ���

			//�ȼ���Ƿ񳤶�����
			if (command.size() != 6)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			std::vector<float> move_num = Convert(command[5]);
			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "��" << index << "���д�" << command[5] << "�����������\n";
				return;
			}
			else
			{
				if (ring_list[ring_index].Move(point_index, move_num))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
					return;
				}
			}
		}
		else if (command[3] == "del")
		{
			//ɾ����

			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			int point_index = -1;//��¼���
			if (StringToFloat(command[4]).str_status)
			{
				point_index = StringToFloat(command[4]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[4] << "�����������\n";
				return;
			}

			if (ring_list[ring_index].Delete(point_index))
			{
				return;
			}
			else
			{
				std::cout << "��" << index << "���д����������" << command[4] << "Խ��\n";
				return;
			}
		}
		else if (command[3] == "set_length")
		{
			//���ó���

			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}
			ring_list[ring_index].SetLength(command[4]);
		}
		else if (command[3] == "set_area")
		{
			//���ó���

			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			ring_list[ring_index].SetArea(command[4]);
		}
		else if (command[3] == "name")
		{
			//��������

			//�ȼ���Ƿ񳤶�����
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			ring_list[ring_index].SetName(command[4]);
		}
		else
		{
			std::cout << "��" << index << "���д�û��" << command[3] << "ָ��\n";
		}
	}
}

void Set(std::vector <Polygon>& polygon_list, const std::vector<std::string> command, const int index)
{
	int poly_index;//�洢����Ҫ�����Ķ����
	bool have_poly = 0;//����Ƿ�������Ҫ�ҵĶ����

	for (int i = 0; i < polygon_list.size(); ++i)
	{
		if (polygon_list[i].GetVarName() == command[2])
		{
			poly_index = i;
			have_poly = 1;
			break;
		}
	}

	if (!have_poly)
	{
		std::cout << "��" << index << "���д�" << command[2] << "������\n";
		return;
	}
	else
	{
		if (command[3] == "inner")
		{
			if (command.size() != 5)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			std::vector<float> point_num = Convert(command[4]);//�洢��������Ϣ
			if (point_num.size() % 2 == 0)
			{
				polygon_list[poly_index].Set(point_num);
				return;
			}
			else
			{
				std::cout << "��" << index << "���д������������������Ƿ�ɶ�\n";
				return;
			}
		}
		else if (command[3] == "set")
		{
			//�޸ĵ�������Ϣ������outer ��inner
			if (command.size() != 7)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			std::vector<float> point_num = Convert(command[6]);//�洢��������Ϣ
			int point_index = -1;//��¼���
			if (StringToFloat(command[5]).str_status)
			{
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[5] << "�����������\n";
				return;
			}

			if (point_num.size() != 2)
			{
				std::cout << "��" << index << "���д�����" << command[6] << "�����������\n";
				return;
			}
			else
			{
				if (command[4] == "outer")
				{
					if (polygon_list[poly_index].SetOuter(point_index, point_num))
					{
						return;
					}
					else
					{
						std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
						return;
					}
				}
				else if (command[4] == "inner")
				{
					if (polygon_list[poly_index].SetInner(point_index, point_num))
					{
						return;
					}
					else
					{
						std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
						return;
					}
				}
				else
				{
					std::cout << "��" << index << "���д�ָ��" << command[4] << "������\n";
				}

			}
		}
		else if (command[3] == "move")
		{
			//�ƶ���
			if (command.size() != 7)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}

			std::vector<float> move_num = Convert(command[6]);
			int point_index = -1;//��¼���
			if (StringToFloat(command[5]).str_status)
			{
				//����������С����ֻȡ����λ
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[5] << "�����������\n";
				return;
			}

			if (move_num.size() != 2)
			{
				std::cout << "��" << index << "���д�" << command[6] << "�����������\n";
				return;
			}
			else
			{
				if (command[4] == "outer")
				{
					if (polygon_list[poly_index].MoveOuter(point_index, move_num))
					{
						return;
					}
					else
					{
						std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
						return;
					}
				}
				else if (command[4] == "inner")
				{
					if (polygon_list[poly_index].MoveInner(point_index, move_num))
					{
						return;
					}
					else
					{
						std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
						return;
					}
				}
				else
				{
					std::cout << "��" << index << "���д�ָ��" << command[4] << "������\n";
				}
			}
		}
		else if (command[3] == "del")
		{
			//ɾ����
			if (command.size() != 6)
			{
				std::cout << "��" << index << "���д��������Ƿ����\n";
				return;
			}
			int point_index = -1;//��¼���
			if (StringToFloat(command[5]).str_status)
			{
				point_index = StringToFloat(command[5]).result;
			}
			else
			{
				std::cout << "��" << index << "���д����" << command[5] << "�����������\n";
				return;
			}

			if (command[4] == "outer")
			{
				if (polygon_list[poly_index].DeleteOuter(point_index))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
					return;
				}

			}
			else if (command[4] == "inner")
			{
				if (polygon_list[poly_index].DeleteInner(point_index))
				{
					return;
				}
				else
				{
					std::cout << "��" << index << "���д����������" << command[5] << "Խ��\n";
					return;
				}
			}
			else
			{
				std::cout << "��" << index << "���д�ָ��" << command[4] << "������\n";
			}
		}
		else if (command[3] == "set_length")
		{
			//���ó���
			polygon_list[poly_index].SetLength(command[4]);
		}
		else if (command[3] == "set_area")
		{
			//���ó���
			polygon_list[poly_index].SetArea(command[4]);
		}
		else if (command[3] == "name")
		{
			//��������
			polygon_list[poly_index].SetName(command[4]);
		}
		else
		{
			std::cout << "��" << index << "���д�û��" << command[3] << "ָ��\n";
		}
	}
}

int Judge(std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "equal")
	{
		//���ڵ㼯��˵����ȱ�����в���equal��������������Ϊ����ַ���
		std::cout << "��" << index << "�д�����ָ�����\n";
		return 2;
	}
	else
	{
		Point p1;
		Point p2;
		bool have_p1 = 0;//����p1�Ƿ����
		bool have_p2 = 0;//����p2�Ƿ����
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[2])
			{
				p1 = point_list[i];
				have_p1 = 1;

			}
			if (point_list[i].GetVarName() == command[4])
			{
				p2 = point_list[i];
				have_p2 = 1;
			}

			if (have_p1 && have_p2)
			{
				break;
			}
		}

		if (!have_p1)
		{
			std::cout << "��" << index << "������";
			std::cout << command[2] << "������";
			std::cout << "\n";
			return 2;
		}
		if (!have_p2)
		{
			std::cout << "��" << index << "������";
			std::cout << command[4] << "������";
			std::cout << "\n";
			return 2;
		}
		else
		{
			if (p1.Judge(p2))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
	}
}

int Judge(std::vector<Ring>& ring_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "cover")
	{
		//���ڵ㼯��˵����ȱ�����в���equal��������������Ϊ����ַ���
		std::cout << "��" << index << "�д�����ָ�����\n";
		return 2;
	}
	else
	{
		Ring r;
		Point p;
		bool have_r = 0;//���ٻ�r�Ƿ����
		bool have_p = 0;//���ٵ�p�Ƿ����
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[4])
			{
				p = point_list[i];
				have_p = 1;
				break;
			}
		}

		for (int i = 0; i < ring_list.size(); ++i)
		{
			if (ring_list[i].GetVarName() == command[2])
			{
				r = ring_list[i];
				have_r = 1;
				break;
			}
		}
		if (!have_p)
		{
			std::cout << "��" << index << "������";
			std::cout << command[4] << "������";
			std::cout << "\n";
			return 2;
		}

		if (!have_r)
		{
			std::cout << "��" << index << "������";
			std::cout << command[2] << "������";
			std::cout << "\n";
			return 2;
		}

		else
		{
			if (r.Judge(p))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	}
}

int Judge(std::vector <Polygon>& polygon_list, std::vector<Point>& point_list, const std::vector<std::string> command, const int index)
{
	if (command.size() != 5 && command[3] != "cover")
	{
		//���ڵ㼯��˵����ȱ�����в���equal��������������Ϊ����ַ���
		std::cout << "��" << index << "�д�����ָ�����\n";
		return 2;
	}
	else
	{
		Ring r;
		Point p;
		bool have_r = 0;//���ٻ�r�Ƿ����
		bool have_p = 0;//���ٵ�p�Ƿ����
		for (int i = 0; i < point_list.size(); ++i)
		{
			if (point_list[i].GetVarName() == command[4])
			{
				p = point_list[i];
				have_p = 1;
				break;
			}
		}

		for (int i = 0; i < polygon_list.size(); ++i)
		{
			if (polygon_list[i].GetVarName() == command[2])
			{
				r = polygon_list[i].GetOuter();
				have_r = 1;
				break;
			}
		}
		if (!have_p)
		{
			std::cout << "��" << index << "������";
			std::cout << command[4] << "������";
			std::cout << "\n";
			return 2;
		}
		if (!have_r)
		{
			std::cout << "��" << index << "������";
			std::cout << command[2] << "������";
			std::cout << "\n";
			return 2;
		}


		else
		{
			if (r.Judge(p))
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}

	}
}

std::vector<float> Convert(std::string command)
{
	std::vector<float> float_result;//�洢ת�����
	std::vector<std::string> divide_result = DivideStr(command, ',');//�зֵ�����
	for (int i = 0; i < divide_result.size(); ++i)
	{
		Fresult convert_result = StringToFloat(divide_result[i]);//�ַ���ת������
		if (convert_result.str_status)
		{
			float_result.push_back(convert_result.result);
		}
		else
		{
			std::cout << divide_result[i] << "�����⣬����ת��ʧ��\n";
		}
	}
	return float_result;
}