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
        ll n,m,k;cin>>n>>m>>k;
        ll mn = min(n/(m+1),n-(m*k));
        // cout<<mn<<"\n";
        ll cnt = 0;
        vll res(n);
        if(k>=mn){
            for (int i = 0; i < mn; i++)
            {   
                for (int j = i; j < n; j+=k)
                {
                    res[j] = i;
                }            
            }
        }else{
            for (int i = 0; i < n; i++)
            {
                res[i] = cnt%mn;
                cnt++;
            }
            // cout<<"\n";
        }
        for(auto x:res)cout<<x<<" ";        
        cout<<"\n";
        
    }

    return 0;
}