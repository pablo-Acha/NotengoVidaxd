#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int,int>> prr(n);
    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        auto &[a,b]  = prr[i];
        cin>>a>>b;
        mp[b]++;
    }
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        res+= mp[prr[i].first];
    }
    cout<<res<<"\n";
    
    return 0;
}