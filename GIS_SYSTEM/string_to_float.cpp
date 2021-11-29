/*�ַ���ת����*/

#include <iostream>
#include "string_to_float.h"
#include <string>
#include <float.h>

using namespace std;

struct Fresult StringToFloat(string number_string)
{
    Fresult return_result = {0, 0};//���淵�ؽ��
    double num = 0;//��������������һ����Ҫ�������float��Χ����ֵ�����������Χ�����ǽ��б�����
    int decimal = 0;//��¼С��λ��
    int minus = 1;//���ţ�����ת��������
    bool point = false;//��¼�Ƿ�������С����
    
    const char* cstr = number_string.c_str();//�ַ���ָ��

    //�ж��Ƿ�Ϊ��ָ����߿��ַ�
    if ((cstr != NULL) && (*cstr != '\0'))
    {
        //�жϳ��˷���λ֮�⣬�Ƿ�ȫ����Ȼ����С����ҲҪ�ų���
        //�������
        if (*cstr == '-')
        {
            minus = -1;
            cstr++;
        }
        else
        {
            minus = 1;
            if (*cstr == '+')
            {
                cstr++;
            }
        }
        while (*cstr != '\0')
        {

            if (*cstr >= '0' && *cstr <= '9')
            {
                //stringת����
                if (!point)
                {
                    num = num * 10 + ((double)*cstr - '0');
                }
                else
                {
                    ++decimal;
                    
                    num += ((double)*cstr - '0') / pow(10, decimal);
                }
                cstr++;

                //����32bit����
                if (num <= FLT_MAX && num >= 0)
                {
                    return_result.result = (float)num;
                    return_result.str_status = 1;
                }
                else
                {
                    //����float��Χ,����Խ�籨��
                    return_result.result = 0;
                    return_result.str_status = 0;
                    break;
                }

            }
            else if (*cstr=='.')
            {
                point = true;
                ++cstr;
            }
            else
            {
                //������ڷ����ֻ���С���㣬����
                return_result.result = 0;
                return_result.str_status = 0;
                break;
            }
        }
    }
    else
    {
        //�ַ�Ϊ���ַ���ֱ�ӷ���״̬����
        return_result.result = 0.0f;
        return_result.str_status = 0;
    }

    return_result.result = minus * return_result.result;

    return return_result;
}

std::string trim(std::string& str)
{

    str.erase(0, str.find_first_not_of(" \t")); // ȥ��ͷ���ո�
    str.erase(str.find_last_not_of(" \t") + 1); // ȥ��β���ո�
    return str;

}
