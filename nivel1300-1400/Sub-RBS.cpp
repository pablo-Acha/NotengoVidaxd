#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        vll a(n+1),c(n+1);
        s  = '0'+s;
        for (int i = 1; i <=n; i++)
        {
            a[i] = (s[i] == '(') +a[i-1];
            c[i] = (s[i] == ')') +c[i-1];
        }
        // for(auto x:a)cout<<x<<" ";cout<<"\n";
        // for(auto x:c)cout<<x<<" ";cout<<"\n";
        ll x = 0;
        ll res = -1;
        
        for (int i = 1; i <= n; i++)
        {
            if(s[i] == ')')x = i;
            else{
                if(x>0 && a[i-1] - a[x-1]<= c[n]-c[i] && 
                c[i-1] - c[x-1]<= a[n]-a[i] ){
                    // cout<<i<<"\n";
                    res = max(res, n-((i-x)*2));
                }
            }   
        }
        cout<<(res)<<"\n";
         


    }

    return 0;
}