#include "vec4.h"
#include <iostream>

void print(Vec4& vec4)
{
    for (int i(0); i < 4; ++i)
        std::cout << vec4[i] << "\t";
    std::cout << std::endl;
}

int main()
{
    Vec4 vec;
    print(vec);
    vec[1] = 5;
    print(vec);
    vec += 7;
    print(vec);
    Vec4 vec2(6);
    print(vec2);
    Vec4 vec3(1, 2, 3, 4);
    print(vec3);
    vec = vec2 * vec3;
    print(vec);
    return 0;
}
