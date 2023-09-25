#include <bits/stdc++.h>
using namespace std;

//判断是否为质数
int IsPrime(int x)
{
    if (1 == x)
        return 0;
    for (int i = 2; i <= sqrt(x); i++)
        if (x%i == 0)
            return 0;
    return 1;
}