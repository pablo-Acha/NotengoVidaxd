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
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n+1);
        vll cop(n);
        vll freq(n+1);
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            cop[i] = a;
            freq[a]++;
        }
        arr[1]= 0;
        sort(cop.begin(),cop.end());
        for (int i = 2; i <= n; i++)
        {
            arr[i]= (lower_bound(cop.begin(),cop.end(),(i*4)+1)-cop.begin());
            ll mx = (i*4) + 1;
            for (int j = i; j <= min(n,mx) ;j+=i)
            {
                arr[i]-=freq[j];
            }        
        }
        ll res = 1;
        for (int i = n; i >= 1; i--)
        {
            if(arr[i]<=k){
                res= i;
                break;
            }
        }
        // for(auto a:arr){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        cout<<res<<"\n";
    }
    
    return 0;
}