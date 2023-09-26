#include <bits/stdc++.h>
using namespace std;

int strStr_next(string s, string p) {
    int n = s.size(), m = p.size();
    if(m == 0) return 0;
    //设置哨兵
    s.insert(s.begin(),' ');
    p.insert(p.begin(),' ');
    vector<int> next(m + 1);
    //预处理next数组
    for(int i = 2, j = 0; i <= m; i++){
        while(j and p[i] != p[j + 1]) j = next[j];
        if(p[i] == p[j + 1]) j++;
        next[i] = j;
    }
    //for(int i = 1; i <= m; i++) cout << next[i] << endl;
    //匹配过程
    for(int i = 1, j = 0; i <= n; i++){
        while(j and s[i] != p[j + 1]) j = next[j];
        if(s[i] == p[j + 1]) j++;
        if(j == m) return i - m;
    }
    return -1;
}

//输出s串中所有t的位置
int strStr_next1(string s, string p,vector<int> &next) {
    int n = s.size(), m = p.size();
    if(m == 0) return 0;
    //设置哨兵
    s.insert(s.begin(),' ');
    p.insert(p.begin(),' ');
    next.resize(m + 1);
    //预处理next数组
    for(int i = 2, j = 0; i <= m; i++){
        while(j and p[i] != p[j + 1]) j = next[j];
        if(p[i] == p[j + 1]) j++;
        next[i] = j;
    }
    //匹配过程
    for(int i = 1, j = 0; i <= n; i++){
        while(j and s[i] != p[j + 1]) j = next[j];
        if(s[i] == p[j + 1]) j++;
        if(j == m) cout << i - m + 1 << endl;
    }
    for(int i = 1; i <= m; i++) cout << next[i] << " ";
    cout << endl;
    return 0;
}


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
    cout << strStr_next(s,t) << endl;
    return 0;
}
