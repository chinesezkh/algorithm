#include <bits/stdc++.h>
using namespace std;
// f[k] 是区间和
long long n,m,a[500'000],f[500'000 * 4 + 1],v[500'000 * 4 + 1];

inline void build(int k,int l,int r){
    if(l == r) {
        f[k] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(k + k,l,m);
    build(k + k + 1,m + 1,r);
    f[k] = f[k + k] + f[k + k + 1];
    return;
}


//下标对应的是K的点，对应区间是l到r，要在x的点加上y
inline void add(int k,int l,int r,int x,int y) {
    f[k] += y;
    if(l == r)
        return;
    int m = (l + r) >> 1;
    if(x <= m) add(k + k,l,m,x,y);
    else add(k + k + 1,m + 1,r,x,y);
    return;
}

//下标为k对应l到r的子区间，求s到t的区间和
int calc (int k,int l,int r,int s,int t){
    if(l == s && r == t)
        return f[k];
    int m = (l + r) >> 1;
    if (t <= m) 
        calc(k + k,l,m,s,t);
    else if(s > m)
        calc(k + k + 1,m + 1,r,s,t);
    else {
        return calc(k + k,l,m,s,m) + calc(k + k + 1,m + 1,r,m + 1,t);
    }
}

//区间更新
//下标对应的是K的点，对应区间是l到r，要在s到t的区间上的所有点加上y
inline void update(int k,int l,int r,int s,int t,int y) {
    f[k] += (t - s + 1) * y;
    if(l == r)
        return;
    int m = (l + r) >> 1;
    if (t <= m) 
        update(k + k,l,m,s,t,y);
    else if(s > m)
        update(k + k + 1,m + 1,r,s,t,y);
    else {
        update(k + k,l,m,s,m,y);
        update(k + k + 1,m + 1,r,m + 1,t,y);
    }
    return;
}

inline void build_tag(int k,int l,int r){
    v[k] = 0;
    if(l == r) {
        f[k] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(k + k,l,m);
    build(k + k + 1,m + 1,r);
    f[k] = f[k + k] + f[k + k + 1];
    return;
}

//区间更新 tag
//下标对应的是K的点，对应区间是l到r，要在s到t的区间上的所有点加上y
//v[k]表示k点对应的区间上面的每个数字都要加上v[k]
inline void update_tag(int k,int l,int r,int s,int t,int y) {
    if(l == s && r == t){
        v[k] += y;
        return;
    }
    f[k] += (t - s + 1) * y;
    int m = (l + r) >> 1;
    if (t <= m) 
        update_tag(k + k,l,m,s,t,y);
    else if(s > m)
        update_tag(k + k + 1,m + 1,r,s,t,y);
    else {
        update_tag(k + k,l,m,s,m,y);
        update_tag(k + k + 1,m + 1,r,m + 1,t,y);
    }
    return;
}

//下标为k对应l到r的子区间，求s到t的区间和
long long calc_tag (int k,int l,int r,int s,int t,long long p){
    p += v[k];
    if(l == s && r == t)
        return p * (r - l + 1) + f[k];
    int m = (l + r) >> 1;
    if (t <= m) 
        calc_tag(k + k,l,m,s,t,p);
    else if(s > m)
        calc_tag(k + k + 1,m + 1,r,s,t,p);
    else {
        return calc_tag(k + k,l,m,s,m,p) + calc_tag(k + k + 1,m + 1,r,m + 1,t,p);
    }
}


int main(){
    cin >> n >> m;
    for(int i = 1;i <= n; i++) 
        scanf("%d",&a[i]);
    build_tag(1,1,n);
    for(int i = 0;i < m; i++){
        int t,x,y;
        long long k;
        scanf("%d",&t);
        if (t == 1) {
            scanf("%d%d%lld",&x,&y,&k);
            update_tag(1,1,n,x,y,k);
        }
        if (t == 2){
            scanf("%d%d",&x,&y);
            cout << calc_tag(1,1,n,x,y,0) << endl;
        }
    }

    return 0;
}