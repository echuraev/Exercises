#ifndef EXPR_H
#define EXPR_H

#include "table.h"
#include "lex.h"
#include <string>


class Node
{
public:
    Node();
    ~Node();
    void setVal(const char ch);
    void setVal(const char *str);
    void setVal(const double num);
    char *getVal();
    inline Node *getNext() {return m_next;}
    template <typename T> Node &operator+=(T val);
private:
    Node *lastNode();
    Node *m_next;
    char *m_val;
};

enum ExprPackage
{
    NODE, STR
};

class Expr
{
public:
    Expr(const char*, ExprPackage);
    ~Expr();
    double eval();
    void print();
private:
    void addNode();
    double expr();
    double term();
    double prim();
    const char *m_expr;
    Table m_table;
    Lex m_lex;
    Node *m_exprNode;
    std::string m_exprStr;
};

#endif
