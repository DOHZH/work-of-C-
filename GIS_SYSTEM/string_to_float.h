//�ṩ�������ݣ��ַ�ת����
#ifndef STRING_TO_FLOAT_H
#define STRING_TO_FLOAT_H
#include <string>

//�ṹ�壬���ڴ洢�ַ����Ϸ�״̬��ת���Ľ��
struct Fresult
{
    bool str_status;//����ַ����Ƿ�Ϸ���0���Ϸ���1�Ϸ�
    double result;//�洢�����
};

//�ṩ������ַ�����ת���ֵĹ���
struct Fresult StringToFloat(std::string);
//ȥ����λ�ո�
std::string trim(std::string& str);
#endif // STRING_TO_FLOAT_H