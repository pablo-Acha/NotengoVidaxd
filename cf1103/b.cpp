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
        int n,k;cin>>n>>k;
        string s;cin>>s;
        vll vis(n);
        for (int i = 0; i < n-k; i++)
        {
            if(vis[i])continue;
            for (int j = i; j < n-k; j+=k)
            {
                vis[j] = 1;
                if(s[j] == '1'){
                    s[j] = '0';
                    s[j+k] = (s[j+k] == '1')?'0':'1';
                }
            }     
        }
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '1'){f = 0;break;}
        }
        cout<<(f?"YES\n":"NO\n");
    }
    return 0;
}