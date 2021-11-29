//提供输入内容，字符转数字
#ifndef STRING_TO_FLOAT_H
#define STRING_TO_FLOAT_H
#include <string>

//结构体，用于存储字符串合法状态与转化的结果
struct Fresult
{
    bool str_status;//标记字符串是否合法，0不合法，1合法
    double result;//存储结果。
};

//提供输入的字符内容转数字的功能
struct Fresult StringToFloat(std::string);
//去除首位空格
std::string trim(std::string& str);
#endif // STRING_TO_FLOAT_H