#include <bits/stdc++.h>
using namespace std;

long long quickPow(long long b,long long i){
    long long res = 1;
    while(i){
        if(i&1)
            res*=b;
        b*=b;
        i>>=1;
    }
    return res;
}