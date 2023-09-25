#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;
int fa[maxn];
void init(int n){
    for(int i=0;i<n;i++){
        fa[i]=i;
    }
}
int find(int x){
    if(x!=fa[x]) fa[x]=find(fa[x]);
    return fa[x];
}
void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    fa[x]=y;
}

void solve(){
    int m,n,t,x,y;
    cin >> n >> m;
    init(n + 1);
    for(int i = 0; i < m; i++){
        cin >> t >> x >> y;
        if (t == 1) {
            unite(x,y);
        } else {
            if(find(x) == find(y)) cout << "Y" << endl;
            else cout << "N" << endl;
        }
    }
    return;
}

int main(){
    solve();
    return 0;
}
