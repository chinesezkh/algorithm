#include <bits/stdc++.h>
using namespace std;

//每个要求都是一种状态，然后根据每种状态的变化转移
class Solution {
public:
    int stringCount(int n) {
        const int mod = 1e9 + 7;
        int res = 0;
        long long f[n + 1][2][3][2];
        memset(f,0,sizeof(f));
        f[0][0][0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 2; l++){
                        //下一个字符填写什么
                        f[i][j][k][l] += f[i - 1][j][k][l] * 23;
                        f[i][j][k][l] %= mod;
                        f[i][min(j + 1,1)][k][l] += f[i - 1][j][k][l];
                        f[i][min(j + 1,1)][k][l] %= mod;
                        f[i][j][min(k + 1,2)][l] += f[i - 1][j][k][l];
                        f[i][j][min(k + 1,2)][l] %= mod;
                        f[i][j][k][min(l + 1,1)] += f[i - 1][j][k][l];
                        f[i][j][k][min(l + 1,1)] %= mod;
                    }
                }
            }
        }
        return f[n][1][2][1];
    }
};