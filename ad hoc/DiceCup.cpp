#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){

    int n,m;cin>>n>>m;
        map<int,int> mp;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                mp[i+j]++;                
            }
        }
        ll mx = -1;
        vector<int> res;
        for(auto [a,b]:mp){
            if(b>mx){
                mx = b;
            }
        }
        for(auto [a,b]:mp){
            if(b == mx){
                res.push_back(a);
            }
        }
        for (int i = 0; i < res.size(); i++)
        {
            cout<<res[i]<<"\n";
        }

    
    return 0;
}