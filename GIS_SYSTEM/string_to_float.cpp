/*字符串转数字*/

#include <iostream>
#include "string_to_float.h"
#include <string>
#include <float.h>

using namespace std;

struct Fresult StringToFloat(string number_string)
{
    Fresult return_result = {0, 0};//储存返回结果
    double num = 0;//储存输出结果。这一步主要处理符合float范围的数值，如果超出范围，我们进行报错处理
    int decimal = 0;//记录小数位数
    int minus = 1;//符号，用于转换正负号
    bool point = false;//记录是否遇到了小数点
    
    const char* cstr = number_string.c_str();//字符串指针

    //判断是否为空指针或者空字符
    if ((cstr != NULL) && (*cstr != '\0'))
    {
        //判断除了符号位之外，是否全是自然数（小数点也要排除）
        //处理符号
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
                //string转数字
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

                //处理32bit数据
                if (num <= FLT_MAX && num >= 0)
                {
                    return_result.result = (float)num;
                    return_result.str_status = 1;
                }
                else
                {
                    //超出float范围,进行越界报错
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
                //如果存在非数字或者小数点，报错
                return_result.result = 0;
                return_result.str_status = 0;
                break;
            }
        }
    }
    else
    {
        //字符为空字符，直接返回状态错误
        return_result.result = 0.0f;
        return_result.str_status = 0;
    }

    return_result.result = minus * return_result.result;

    return return_result;
}

std::string trim(std::string& str)
{

    str.erase(0, str.find_first_not_of(" \t")); // 去掉头部空格
    str.erase(str.find_last_not_of(" \t") + 1); // 去掉尾部空格
    return str;

}
