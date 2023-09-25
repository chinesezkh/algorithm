#include <bits/stdc++.h>
using namespace std;

void monotoneStack(vector<int> &nums1,vector<int> &nums2,vector<int> &res){
    vector<pair<int,int>>v;
    map<int,pair<int,int>> mp;
    for(int i = 0; i < nums2.size(); i++){
        if(v.empty()){
            v.push_back({nums2[i],i});
        } else {
            while(!v.empty() && nums2[i] > v.back().first){
                mp[v.back().first] = {nums2[i],i};
                v.pop_back();
            }
            v.push_back({nums2[i],i});
        }
    }
    for(int i = 0; i < nums1.size(); i++){
        if(mp.find(nums1[i]) != mp.end()){
            res.push_back(mp[nums1[i]].second + 1);
        } else {
            res.push_back(0);
        }
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<int> v(n),res;
    for(int i = 0; i < n; i++) scanf("%d",&v[i]);
    monotoneStack(v,v,res);
    for(auto x:res) cout << x << " ";
    cout << endl;
    return 0;
}