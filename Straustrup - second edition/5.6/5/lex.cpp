#include "lex.h"
#include "error.h"
#include <ctype.h>
#include <math.h>

Lex::Lex()
{}

Lex::~Lex()
{}

token_value Lex::getToken(const char *(&ch))
{
    while (*ch != '\n' && isspace(*ch)) 
    {
        ch++;
    }

    switch(*ch)
    {
    case ';':
    case '\n':
    case '\0':
        return m_currTok = PRINT;
    case '*':
    case '/':
    case '+':
    case '-':
    case '(':
    case ')':
    case '=':
        m_currTok = token_value(*ch);
        ch++;
        return m_currTok;
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case '.':
        m_numberValue = parseNumber(ch);
        return m_currTok = NUMBER;
    default:
        if (isalpha(*ch))
        {
            char* p = m_nameString;
            *p++ = *ch;
            while (++ch && isalnum(*ch))
            {
                *p++ = *ch;
            }
            *p = 0;
            return m_currTok = NAME;
        }
        error("Incorrect lexeme");
        return m_currTok = PRINT;
    }
}

double Lex::parseNumber(const char *(&ch))
{
    double num = 0;
    bool isFraction = false;
    int fraction = 0;
    while(isdigit(*ch) || *ch == '.')
    {
        if (*ch == '.')
        {
            ch++;
            isFraction = true;
            continue;
        }
        num *= 10;
        num += (*ch - '0');
        fraction = (isFraction) ? fraction + 1 : fraction;
        ch++;
    }
    return (fraction == 0) ? num : (num / pow(10.0, fraction));
}
