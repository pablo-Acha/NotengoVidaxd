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
        vi arr(n);for(auto &a:arr)cin>>a;
        set<ll> st;
        ll res = 0;
        for (ll i = 0; i < n; i++)
        {
            for (int j = i-arr[i],h = 1; j >= 0 && h<=arr[i]; j-=arr[i],h++)
            {
                ll aux =arr[j] == h; 
                res += aux;
            }
            for (int j = i+arr[i],h = 1; j < n  && h<arr[i]; j+=arr[i],h++)
            {
                ll aux =arr[j] == h; 
                res += aux;
            }
            
        }
        cout<<res<<"\n";
        
    }

    return 0;
}