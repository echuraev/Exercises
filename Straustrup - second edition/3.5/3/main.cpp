#include <iostream>

int main()
{
    int x = 1;
    return x / 0; // undefined behavior

    int arr[4] = {0, 1, 2, 3};
    int *p = arr + 5;  // undefined behavior

    int f()
    {
    }  /* undefined behavior if the value of the function call is used*/

    i = ++i + 1; // undefined behavior

    a[i] = i++; // undefined behavior
    printf("%d %d\n", ++n, power(2, n)); // also undefined behavior
    
    return 0;
}
