#include "divide_method.h"
#include <string>
#include <vector>
#include <queue>

std::vector<std::string> DivideStr(std::string input, char mark)
{
    const char* cstr = input.c_str();
    std::queue<char> imp_queue;//队列，用来处理切分字符时遇到的非标识符
    std::vector<std::string> result;

    while (*cstr != '\0')
    {
        if (*cstr == mark)
        {
            std::string result_str = "";//用来将弹出的数字字符拼接成一个数字的中转值
            while (!imp_queue.empty())
            {
                result_str.push_back(imp_queue.front());
                imp_queue.pop();
            }
            if (result_str != "")
            {
                result.push_back(result_str);
            }
            ++cstr;
        }
        else
        {
            imp_queue.push(*cstr);
            ++cstr;
            if (*cstr == '\0')
            {
                //如果遇到空指针，说明字符串已经到尽头，从头吧队列中的字符弹出来
                std::string result_str = "";//用来将弹出的数字字符拼接成一个数字的中转值
                while (!imp_queue.empty())
                {
                    result_str.push_back(imp_queue.front());
                    imp_queue.pop();
                }
                if (result_str != "")
                {
                    result.push_back(result_str);
                }
            }
        }
    }

    return result;
}
