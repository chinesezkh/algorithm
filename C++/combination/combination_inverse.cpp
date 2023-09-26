#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 5e6+5, MOD = 998244353;

int fact[N], infact[N];

inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9')
        x=x*10+ch-'0',ch=getchar();
    return x*f;
}

inline int qmi(int a, int k, int p) {
    LL res = 1;
    while (k) {
        if (k & 1) res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

inline LL C(int a,int b){
    return (LL)fact[a] * infact[a - b] % MOD * infact[b] % MOD;
}

int main() {
    int n,t,a,b,res = 0;
    t = read();
    n = read();
    fact[0] = infact[0] = 1;
    for (int i = 1 ; i <= n; ++i) {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = (LL)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
    
    while (t--) {
        a = read();
        b = read();
        // cab = fact[a] * infact[a - b] % MOD * infact[b] % MOD
        res ^= C(a,b);
    }
    cout << res << endl;
    return 0;
}
