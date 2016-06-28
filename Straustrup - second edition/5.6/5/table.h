#ifndef TABLE_H
#define TABLE_H

class Name
{
public:
    Name();
    Name(const char *name, Name *next);
    ~Name();
    inline void setValue(double val) {m_value = val;}
    inline double getValue() {return m_value;}
    inline Name *getNext() {return m_next;}
    inline const char *getName() {return m_name;}
private:
    void freeName(Name *name);
    char *m_name;
    Name *m_next;
    double m_value;
};

class Table
{
public:
    Table();
    ~Table();
    inline Name *operator[](unsigned int i) {return m_table[i];}
    Name *look(const char* p, int ins = 0);
    Name *insert(const char* s);
private:
    const int TBLSZ;
    Name **m_table;
};

#endif
