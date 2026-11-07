#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    ll tam = 3e5+10;
    vector<vll> div(tam);
    for (int i = 2; i < tam; i++)
    {
        for (int j = i+i; j < tam; j+=i)
        {
            div[j].push_back(i);
        }
    }
    
    while (t--)
    {
        ll n;cin>>n;
        set<ll> st;
        vll res(n+1,-1);        
        for(int i = 0; i<n;i++){ll a;cin>>a;res[a] = 1;}
        for (ll i = 2; i <= n; i++)
        {
            if (res[i] == 1)
            {
                ll h = 2;
                for (ll j = i * i; j <= n; j *= i, h++)
                {
                    if (res[j] == -1)res[j] = h;
                    else res[j] = min(h, res[j]);
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<res[i+1]<<" ";
        // }
        // cout<<"\n";
        // for(auto x:div[8]){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        for (int i = 2; i <=n ; i++)
        {
            if(res[i] == -1 || res[i]>1 ){
                ll mn = 1e6;
                if(div[i].size() == 0)continue;
                for(auto x:div[i]){
                    if(res[x]!=-1 && res[i/x]!=-1){
                        mn = min(mn,res[x]+res[i/x]);    
                    }
                }
                // cout<<(i == 6? mn:0)<<"\n";
                res[i]= (mn != 1e6)?mn:-1;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}