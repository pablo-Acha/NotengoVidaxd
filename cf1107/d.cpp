#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--) {
        ll n;cin>>n;
        vll arr(n+1);
        vll brr(n+1);
        for (int i =1; i <= n; i++)
        {
            cin>>arr[i];
        }
        for (int i =1; i <= n; i++)
        {
            cin>>brr[i];
        }
        bool f = 1;
        for (int i = 1; i <= n; i++)
        {
            if(i<n && arr[i]<brr[i]){
                arr[i+1] -= brr[i]-arr[i];
            } 
            if(arr[i]>brr[i]){
                f = 0;
                break;
            }
        }
        cout<<(f?"YES\n":"NO\n");
        
    }
}