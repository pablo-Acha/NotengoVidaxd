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
        ll n,k;cin>>n>>k;
        vll arr(n);
        ll mn = 0;
        ll temp = n;
        while(temp%2 == 0){
            mn++;
            temp/=2;
        }
        // cout<<mn<<"\n";
        // cout<<(1LL<<mn)<<"\n";
        for (int i = 0; i < 1LL<<mn; i++)
        {
            arr[i] = k;
        }
                // for(auto x:arr)cout<<x<<" ";cout<<"\n";
        for (int i = mn+1; (1LL<<i) <= n; i++)
        {
            if((n>>i)&1){
                // cout<<i<<"\n";
                ll tam = i;
                for (ll j = 1LL<<i,h = 0; j < (1LL<<(i+1)) && j<n; j++,h++)
                {
                    arr[j] = arr[h];
                }
                // for(auto x:arr)cout<<x<<" ";cout<<"\n";
                
            }
        }
        for(auto x:arr)cout<<x<<" ";cout<<"\n";
        
    }

    return 0;
}