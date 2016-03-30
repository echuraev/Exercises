#include <iostream>

int main()
{
    char input_line[] = "What? Who? And where?";
    char *p = input_line;
    int quest_count = 0;

    while(*p)
    {
        if (*p == '?')
            quest_count++;
        *p++;
    }

    std::cout << "Quest count: " << quest_count << std::endl;

    return 0;
}
