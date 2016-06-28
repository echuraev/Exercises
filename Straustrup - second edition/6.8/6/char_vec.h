#ifndef CHAR_VEC_H
#define CHAR_VEC_H

class char_vec
{
public:
    static char_vec *new_char_vec(int s);
    char& operator[] (int i) {return element[i];}
private:
    int sz;
    char element[1];
};

#endif
