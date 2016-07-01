#include "vec4.h"

Vec4::Vec4()
{
    m_vec4.push_back(0);
    m_vec4.push_back(0);
    m_vec4.push_back(0);
    m_vec4.push_back(0);
}

Vec4::Vec4(double val)
{
    m_vec4.push_back(val);
    m_vec4.push_back(val);
    m_vec4.push_back(val);
    m_vec4.push_back(val);
}

Vec4::Vec4(double val1, double val2, double val3, double val4)
{
    m_vec4.push_back(val1);
    m_vec4.push_back(val2);
    m_vec4.push_back(val3);
    m_vec4.push_back(val4);
}

Vec4::Vec4(const Vec4& vec4)
{
    m_vec4.resize(4);
    clone(vec4);
}

Vec4::~Vec4()
{
    m_vec4.clear();
}

double& Vec4::operator[](int i)
{
    if (i < 0 || i > 3)
        exit(1);
    return m_vec4[i];
}

Vec4& Vec4::operator=(const Vec4& vec4)
{
    m_vec4.clear();
    m_vec4.resize(4);
    clone(vec4);
    return *this;
}

Vec4 Vec4::operator+(const Vec4& vec4)
{
    Vec4 tmp = *this;
    tmp += vec4;
    return tmp;
}

Vec4 Vec4::operator-(const Vec4& vec4)
{
    Vec4 tmp = *this;
    tmp -= vec4;
    return tmp;
}

Vec4 Vec4::operator*(const Vec4& vec4)
{
    Vec4 tmp = *this;
    tmp *= vec4;
    return tmp;
}

Vec4 Vec4::operator/(const Vec4& vec4)
{
    Vec4 tmp = *this;
    tmp /= vec4;
    return tmp;
}

Vec4& Vec4::operator+=(const Vec4& vec4)
{
    for (int i(0); i < 4; ++i)
    {
        m_vec4[i] += vec4.m_vec4[i];
    }
    return *this;
}

Vec4& Vec4::operator-=(const Vec4& vec4)
{
    for (int i(0); i < 4; ++i)
    {
        m_vec4[i] -= vec4.m_vec4[i];
    }
    return *this;
}

Vec4& Vec4::operator*=(const Vec4& vec4)
{
    for (int i(0); i < 4; ++i)
    {
        m_vec4[i] *= vec4.m_vec4[i];
    }
    return *this;
}

Vec4& Vec4::operator/=(const Vec4& vec4)
{
    for (int i(0); i < 4; ++i)
    {
        m_vec4[i] /= vec4.m_vec4[i];
    }
    return *this;
}

void Vec4::clone(const Vec4 &vec4)
{
    for (size_t i(0); i < vec4.m_vec4.size(); ++i)
    {
        m_vec4[i] = vec4.m_vec4[i];
    }
}

