#pragma once
//本文件提供切分字符串的方法
#include <string>
#include <vector>
//切分字符串，第一个参数接受要切分的对象，第二个参数接受切分标志。返回类型为结构体
std::vector<std::string> DivideStr(std::string input, char mark);
//删除指定字符串。参数为需要处理的字符串，需要删除的子串，子串长度
void DeleteSub(std::string& str, const std::string& sub, int n);

