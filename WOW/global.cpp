#include "global.h"
#include <queue>

std::string trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(" \t")); // ȥ��ͷ���ո�
    str.erase(str.find_last_not_of(" \t") + 1); // ȥ��β���ո�
    return str;
}

std::vector<std::string> DivideStr(std::string input, char mark)
{
    const char* cstr = input.c_str();
    std::queue<char> imp_queue;//���У����������з��ַ�ʱ�����ķǱ�ʶ��
    std::vector<std::string> result;

    while (*cstr != '\0')
    {
        if (*cstr == mark)
        {
            std::string result_str = "";//�����������������ַ�ƴ�ӳ�һ�����ֵ���תֵ
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
                //���������ָ�룬˵���ַ����Ѿ�����ͷ����ͷ�ɶ����е��ַ�������
                std::string result_str = "";//�����������������ַ�ƴ�ӳ�һ�����ֵ���תֵ
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
