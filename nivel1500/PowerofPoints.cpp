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
        vll arr(n);for(auto &a:arr)cin>>a;
        vll ind(n);
        iota(all(ind),0);
        sort(all(ind),[&](ll a, ll b){
            return arr[a]<arr[b];
        });
        // for(auto x:ind)cout<<x<<" ";cout<<"\n";
        ll delta = 1;
        sort(all(arr));
        vll res(n);
        for (int i = 1; i < n; i++)
        {
            delta += ((arr[i]-arr[i-1])*i+1);
            res[i] = delta;
        }
        res[0]++;
        delta = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            delta += (abs(arr[i]-arr[i+1])*(n-i-1)+1);
            res[i] += delta;
        }
        res[n-1]++;
        for (int i = 0; i < n; i++)
        {
            arr[ind[i]] = res[i];
        }
        for(auto x:arr)cout<<x-1<<" ";cout<<"\n";
        // for (int i = 0; i < n; i++)
        // {
        //     arr[i] = res[ind[i]];
            
        // }
        
        
    }

    return 0;
}