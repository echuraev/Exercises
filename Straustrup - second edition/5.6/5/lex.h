#ifndef LEX_H
#define LEX_H

enum token_value
{
    NAME,      NUMBER,     END,
    PLUS='+',  MINUS='-',  MUL='*', DIV='/',
    PRINT=';', ASSIGN='=', LP='(',  RP=')'
};

class Lex
{
public:
    Lex();
    ~Lex();
    token_value getToken(const char *(&ch));
    inline token_value getCurrToken() {return m_currTok;};
    inline double getNumberValue() {return m_numberValue;}
    inline char *getNameString() {return m_nameString;}
private:
    double parseNumber(const char *(&ch));
    token_value m_currTok;
    double m_numberValue;
    char m_nameString[256];
};

#endif
