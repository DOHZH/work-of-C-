#pragma once
#include <string>

class Clock
{
public:
	Clock();

	//����ʱ��(����)��Ĭ������ʮ����
	void AddTime(unsigned int added_time=10);

	//���ʱ�̣�����ֵΪ�ַ�����
	std::string PrintTime();

private:
	unsigned int hour_;//ʱ
	unsigned int minute_;//��
};

