#ifndef VEC4_H
#define VEC4_H

#include <vector>

class Vec4
{
public:
    Vec4();
    Vec4(double val);
    Vec4(double val1, double val2, double val3, double val4);
    Vec4(const Vec4& vec4);
    ~Vec4();
    double& operator[](int i);
    Vec4& operator=(const Vec4& vec4);
    Vec4 operator+(const Vec4& vec4);
    Vec4 operator-(const Vec4& vec4);
    Vec4 operator*(const Vec4& vec4);
    Vec4 operator/(const Vec4& vec4);
    Vec4& operator+=(const Vec4& vec4);
    Vec4& operator-=(const Vec4& vec4);
    Vec4& operator*=(const Vec4& vec4);
    Vec4& operator/=(const Vec4& vec4);
private:
    void clone(const Vec4 &vec4);
    std::vector<double> m_vec4;
};

#endif
