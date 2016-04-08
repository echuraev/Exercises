#include <iostream>
#include <sstream>
#include <stdarg.h>

void errorf(const std::string format, ...)
{
    std::stringstream ss;
    va_list ap;
    va_start(ap, format);
    for (size_t i(0); i < format.length(); ++i)
    {
        if (i < (format.length()-1) && format[i] == '\\' && format[i+1] == '%')
        {
            ss << format[i] << format[i + 1];
            i++;
            continue;
        }
        if (i < (format.length()-1) && format[i] == '%')
        {
            char * p;
            char c;
            int num;
            switch (format[i+1])
            {
            case 's':
                p = va_arg(ap, char*);
                ss << p;
                i++;
                continue;
                break;
            case 'c':
                c = va_arg(ap, char);
                ss << c;
                i++;
                continue;
                break;
            case 'd':
                num = va_arg(ap, int);
                ss << num;
                i++;
                continue;
                break;
            default:
                break;
            }
        }
        ss << format[i];
    }
    va_end(ap);
    std::cerr << ss.str();
}

int main()
{
    errorf("ERROR!: %s, %c, %d!\n", "Break", 'e', 123);
    return 0;
}
