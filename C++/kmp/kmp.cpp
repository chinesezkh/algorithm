#include <bits/stdc++.h>
using namespace std;

int strStr(string s, string p) {
    int n = s.size(), m = p.size();
    for(int i = 0; i <= n - m; i++){
        int j = i, k = 0; 
        while(k < m and s[j] == p[k]){
            j++;
            k++;
        }
        if(k == m) return i;
    }
    return -1;
}

int main(){
    string s,t;
    cin >> s >> t;
    cout << strStr(s,t) << endl;
    return 0;
}
