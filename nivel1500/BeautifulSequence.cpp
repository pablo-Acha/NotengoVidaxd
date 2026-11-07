#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

ll power(ll base,ll ex){
    ll res = base;
    for (int i = 0; i < ex; i++)
    {
        res*= 2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    vll pot2(2e5+1);
    pot2[0] = 1;
    for (int i = 1; i < pot2.size(); i++)
    {
        pot2[i] = (pot2[i-1]*2)%MOD;
    }
    
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll tres(n);
        vll unos(n);
        ll acc = 0;
        // for (int i = n - 1; i >= 0; i--)
        // {
        //     if(arr[i] == 2){
        //         acc++;
        //     }
        //     if(arr[i] == 1){
        //         unos[i] = acc;
        //         acc= 0;
        //     }
        // }
        
        acc = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(arr[i] == 3){
                acc++;
            }else if(arr[i] == 2){
                tres[i] = acc;
            }
        }
        for (int i = n -2; i >= 0; i--)
        {
            if(tres[i]>0){
                unos[i] = tres[i];
            }else{
                unos[i] = unos[i+1];
            }
        }
        
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<tres[i]<<" ";
        // }
        // cout<<"\n";
        // for (int i = 0; i < n; i++)
        // {
        //     cout<<unos[i]<<" ";
        // }
        // cout<<"\n";
        vll comb(n);
        ll cur = 0;
        acc = 0;
        ll last = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if(tres[i]>0){
                if(tres[i] == cur){
                    comb[i] = (2*comb[i+1])%MOD;
                }else{
                    cur = tres[i];
                    comb[i] =  ((comb[i+1]*2)%MOD+(2*(cur-last+MOD))%MOD)%MOD;
                    last = cur;     
                }
            }else{
                comb[i] = comb[i+1];
            }
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == 1){
                res = (comb[i]-unos[i]+res+MOD)%MOD;
                // cout<<res<<"\n";
            }
            // cout<<comb[i]<<" ";
        }
        // cout<<"\n";
        
        cout<<res<<"\n";
        
        
    }

    return 0;
}
