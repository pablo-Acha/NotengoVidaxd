#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;
ll dev(ll a){
    if(a == 1){
        return 1;
    }
    return a/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        string s;cin>>s;
        if(n == 1){
            cout<<1<<rnl;
            continue;
        }
        vll si(n+2,1);
        s = '0'+s+'0';
        ll m = s.size();
        ll res = 0;
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if(s[i] == '1') {
                si[i+1] =0;
                si[i] =0;
                si[i-1] =0;
            }          
        }
        si[n+1] =0; 
        si[0] =0; 
        for (int i = 1; i <= n; i++)
        {
            if(si[i] == 1 && si[i+1]==1){
                s[i+1] = '1';
                if(s[i+1] == '1') {
                    si[i+1] =0;
                    si[i] =0;
                    si[i-1] =0;
                }
            }else if(si[i] == 1 && si[i+1] == 0){
                s[i] = '1';
            }
            if(s[i] == '1') {
                // cout<<i<<" ";
                res++;
                si[i+1] =0;
                si[i] =0;
                si[i-1] =0;
            }

        }
           
        
        cout<<res<<rnl;

    }
    
    return 0;
}