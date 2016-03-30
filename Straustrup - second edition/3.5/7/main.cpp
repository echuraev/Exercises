#include <iostream>

int strlen(const char *str)
{
    int len = 0;
    while(*str++) {len++;}
    return len;
}

void strcpy(char *dst, const char *src)
{
    while(*src)
    {
        *dst++ = *src++;
    }
}

int strcmp(const char *str1, const char *str2)
{
    while(*str1 && *str2)
    {
        if (*str1 > *str2)
            return 1;
        else if (*str1 < *str2)
            return -1;
        *str1++;
        *str2++;
    }
    if (*str1)
        return 1;
    else if (*str2)
        return -1;
    return 0;
}

int main()
{
    char str[] = "Hello World!";
    char forCopy[15];
    std::cout << strlen(str) << std::endl;
    strcpy(forCopy, str);
    std::cout << forCopy << std::endl;
    std::cout << strcmp(str, "Hella W") << '\t' << strcmp(str, "Hello World!") << '\t' << strcmp(str, "Hellz W") << std::endl;
    return 0;
}
