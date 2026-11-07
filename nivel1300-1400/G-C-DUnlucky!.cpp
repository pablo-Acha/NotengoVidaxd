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
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        bool f= arr[n-1] == brr[0];
        // for (int i = 0; i < n &&f; i++)
        // {
        //     cout<<i<<"\n";

        //     f&= gcd(arr[i],brr[i]) == min(arr[i],brr[i]);
        // }
        for (int i = 1, j = n-2; i < n && j>=0 && f; i++,j--)
        {   
            // cout<<i<<"\n";

            f&= gcd(arr[i],arr[i-1]) == arr[i];
            f&= gcd(brr[j],brr[j+1]) == brr[j];
        }
        for (int i = 0; i < n-1 && f; i++)
        {
            // cout<<i<<"\n";
            f&= gcd(arr[i],brr[i+1]) == brr[0];
        }
        
        
        cout<<(f?"YES\n":"NO\n");
    }

    return 0;
}