#include <iostream>
#include <string.h>

char *cat(const char *str1, const char *str2)
{
    int length = strlen(str1) + strlen(str2);
    char *catStr = new char[length + 1];
    strcpy(catStr, str1);
    strcat(catStr, str2);
    catStr[length] = '\0';
    return catStr;
}

void rev(char* (&str))
{
    int left = 0;
    int right = strlen(str) - 1;
    do
    {
        char ch = str[left];
        str[left] = str[right];
        str[right] = ch;
        left++;
        right--;
    }
    while(left < right);
}

int main()
{
    char * str = cat("Hello ", "World!");
    std::cout << str << std::endl;
    rev(str);
    std::cout << str << std::endl;
    delete [] str;

    return 0;
}
