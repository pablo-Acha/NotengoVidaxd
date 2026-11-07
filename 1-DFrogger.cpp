#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
bool f(ll x, ll p){
    if((x == 1 && !(p&1)) || (x == 2 &&(p&1))){
        return 1;
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vector<vll> graf(n);
    vll pa(n);
    vector<set<ll>> val(n);

    for (int i = 0; i < n; i++)
    {
        if(arr[i]+i <0 || arr[i]+i>=n)continue;
        graf[i].push_back(arr[i]+i);
        pa[arr[i]+i]++;
    }
    stack<ll> stfir;
    ll res = 0;
    vll vis(n);
    for (int i = 0; i < n; i++)
    {
        if(pa[i] == 0 && vis[i] == 0){
            stfir.push(i);
            set<ll> ayuda;
            while(!stfir.empty()){
                auto x = stfir.top();
                ayuda.insert(arr[x]);
                vis[x] = 1;
                res+= ayuda.size();
                stfir.pop();
                for(auto ni:graf[x]){
                    pa[ni]--;
                    if(pa[ni]>0){
                        for (auto h:ayuda)
                        {
                            val[ni].insert(h);
                        }
                        continue;
                    }
                    if(val[ni].size()>0){
                        for (auto h:val[ni])
                        {
                            ayuda.insert(h);
                        }
                    }
                    stfir.push(ni);
                }
            }
        }
    }
    
    
    for (int i = 0; i < n; i++)
    {
        if(pa[i] == 0)continue;
        pa[i]--;
        ll aux = i;
        stfir.push(aux);
        set<ll> ayuda;
        ll cnt = 0;
        while(!stfir.empty()){
            auto x = stfir.top();
            ayuda.insert(arr[x]);
            cnt++;
            if(val[x].size()>0){
                for(auto a:val[x]){
                    ayuda.insert(a);
                }
            }
            stfir.pop();
            for(auto ni:graf[x]){
                pa[ni]--;
                if(ni == aux)break;
                if(pa[ni]>0)continue;
                stfir.push(ni);
            }
        }
        res+= ayuda.size()*cnt;
        // stfir.push(aux);
        // while(!stfir.empty()){
        //     auto x = stfir.top();
        //     stfir.pop();
        //     for(auto ni:graf[x]){
        //         for (auto h:val[x])
        //         {
        //             val[ni].insert(h);
        //         }
        //         if(ni == aux)break;
        //         stfir.push(ni);
        //     }
        // }
    }
    // ll res = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     res+= val[i].size();
    // }
    cout<<res<<"\n";
    
    return 0;
}