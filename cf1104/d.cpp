#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--)
    {   
        ll n;cin>>n;
        string s;cin>>s;
        char in = s[0];
        vll us(n),cs(n);
        bool f = 0;

        ll res = 0;
        ll u = s[0] == '1', c = s[0] == '0';
        for (int i = 1; i < n; i++)
        {
            u += s[i] == '1';
            c += s[i] == '0';
            if(!f){
                if(s[i] == s[i-1]){
                    f = 1;
                    res +=                    
                }
            }else{
                
                
            }
            cout<<i<<" "<<cs[i]<<" "<<us[i]<<" "<<res<<"\n";
            in = s[i];
        }
        cout<<res<<"\n";
    }
    return 0;
}