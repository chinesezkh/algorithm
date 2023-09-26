#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int N = 2010, MOD = 1e9+7;

int n;
int c[N][N];

//C32 = C[3][2]
void init() {
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j <= i; ++j)
            if (!j) c[i][j] = 1;
            else c[i][j] = (c[i-1][j] + c[i-1][j-1]) % MOD;
}

int main() {
    init();
    
    int n;
    cin >> n;
    
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
    
    return 0;
}
