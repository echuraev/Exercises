#include "expr.h"
#include "lex.h"
#include "error.h"
#include <map>
#include <iostream>
#include <sstream>

Node::Node() : m_next(0), m_val(0)
{}

Node::~Node()
{
    Node *current = this;
    while(current)
    {
        Node *next = current->getNext();
        if (current->getVal())
            delete current->getVal();
        current = 0;
        current = next;
    }
}

void Node::setVal(const char ch)
{
    m_val = new char[2];
    m_val[0] = ch;
    m_val[1] = '\0';
}

void Node::setVal(const char *str)
{
    m_val = new char [strlen(str) + 1];
    strcpy_s(m_val, strlen(str) + 1, str);
}

void Node::setVal(const double num)
{
    std::stringstream ss;
    ss << num;
    const std::string tmp = ss.str();
    m_val = new char [tmp.length() + 1];
    strcpy_s(m_val, tmp.length() + 1, tmp.c_str());
}

char *Node::getVal()
{
    return m_val;
}

template <typename T>
Node &Node::operator+=(T val)
{
    if (!m_val)
    {
        this->setVal(val);
    }
    else
    {
        Node *node = new Node();
        node->setVal(val);
        Node *last = lastNode();
        last->m_next = node;
    }
    return *this;
}

Node *Node::lastNode()
{
    Node *node = this;
    while(node->getNext())
    {
        node = node->getNext();
    }
    return node;
}

Expr::Expr(const char *expr, ExprPackage ep)
{
    m_expr = expr;
    m_lex.getToken(m_expr);
    if (ep == NODE)
    {
        m_exprNode = new Node();
    }
    else
    {
        m_exprStr = expr;
        m_exprNode = 0;
    }
    addNode();
}

Expr::~Expr()
{
    delete m_exprNode;
}

double Expr::eval()
{
    return this->expr();
}

void Expr::print()
{
    if (m_exprNode == 0)
    {
        std::cout << m_exprStr << std::endl;
    }
    else
    {
        for (Node *node = m_exprNode; node != NULL; node = node->getNext())
        {
            std::cout << node->getVal();
        }
        std::cout << std::endl;
    }
}

void Expr::addNode()
{
    if (m_exprNode)
    {
        token_value currTok = m_lex.getCurrToken();
        switch (currTok)
        {
        case NAME:
            *m_exprNode += m_lex.getNameString();
            break;
        case NUMBER:
            *m_exprNode += m_lex.getNumberValue();
            break;
        case END:
            *m_exprNode += '\n';
            break;
        case PLUS:
        case MINUS:
        case MUL:
        case DIV:
        case ASSIGN:
        case LP:
        case RP:
            *m_exprNode += (char)currTok;
            break;
        case PRINT:
            *m_exprNode += '\0';
            break;
        default:
            break;
        }
    }
}

double Expr::expr()
{
    double left = term();
    while(1)
    {
        switch (m_lex.getCurrToken())
        {
        case PLUS:
            m_lex.getToken(m_expr);
            addNode();
            left += term();
            break;
        case MINUS:
            m_lex.getToken(m_expr);
            addNode();
            left -= term();
            break;
        default:
            return left;
        }
    }
}

double Expr::term()
{
    double d;
    double left = prim();
    while(1)
    {
        switch (m_lex.getCurrToken())
        {
        case MUL:
            m_lex.getToken(m_expr);
            addNode();
            left *= prim();
            break;
        case DIV:
            m_lex.getToken(m_expr);
            addNode();
            d = prim();
            if (d == 0) 
                return error("Division by zero");
            left /= d;
            break;
        default:
            return left;
        }
    }
}

double Expr::prim()
{
    std::map<std::string, double (*)(double)> mathFunctions;
    mathFunctions["sqrt"] = sqrt;
    mathFunctions["log"] = log;
    mathFunctions["sin"] = sin;
    double e;
    switch (m_lex.getCurrToken())
    {
    case NUMBER:
        m_lex.getToken(m_expr);
        addNode();
        return m_lex.getNumberValue();
    case NAME:
        if (mathFunctions.count(m_lex.getNameString()))
        {
            if (m_lex.getToken(m_expr) != LP)
                return error("Missed ( after math function");
            addNode();
            m_lex.getToken(m_expr);
            addNode();
            e = mathFunctions[m_lex.getNameString()](expr());
            if (m_lex.getCurrToken() != RP)
                return error("Missed ) after math function");
            return e;
        }
        if (m_lex.getToken(m_expr) == ASSIGN)
        {
            addNode();
            Name *n = m_table.insert(m_lex.getNameString());
            m_lex.getToken(m_expr);
            addNode();
            n->setValue(expr());
            return n->getValue();
        }
        return m_table.look(m_lex.getNameString())->getValue();
    case MINUS:
        m_lex.getToken(m_expr);
        addNode();
        return -prim();
    case LP:
        m_lex.getToken(m_expr);
        addNode();
        e = expr();
        if (m_lex.getCurrToken() != RP)
            return error("Missed )");
        m_lex.getToken(m_expr);
        addNode();
        return e;
    case END:
        return 1;
    default:
        return error("Missed expr");
    }
}

