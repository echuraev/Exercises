#include "table.h"
#include "error.h"
#include <string>

Name::Name() : m_name(NULL), m_next(NULL)
{}

Name::Name(const char *name, Name *next)
{
    m_name = new char[strlen(name) + 1];
    strcpy_s(m_name, strlen(name) + 1, name);
    m_value = 1;
    m_next = next;
}

Name::~Name()
{
    if (m_name)
        delete [] m_name;
    freeName(this);
}

void Name::freeName(Name *name)
{
    if (name == NULL)
        return;
    freeName(name->getNext());
    delete name;
}

Table::Table() : TBLSZ(23)
{
    m_table = new Name * [TBLSZ];
}

Table::~Table()
{
    delete [] m_table;
}

Name *Table::look(const char *p, int ins)
{
    int ii = 0; // hash
    const char *pp = p;
    while (*pp)
    {
        ii = ii<<1 ^ *pp++;
    }
    ii = (ii < 0) ? -ii : ii;
    ii %= TBLSZ;
    for (Name *n = m_table[ii]; n; n = n->getNext())
    {
        if (!strcmp(p, n->getName()))
            return n;
    }
    if (ins == 0)
        error("Undefined variable");
    Name *nn = new Name(p, m_table[ii]);
    m_table[ii] = nn;
    return nn;
}

Name *Table::insert(const char *s)
{
    return look(s, 1);
}
