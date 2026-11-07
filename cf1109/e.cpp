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
        ll n,q;cin>>n>>q;
        string s;cin>>s;
        vll arr(n);
        for (int i = 1; i < n; i++)
        {
            if(s[i] == s[i-1]){
                arr[i]++;
            }
            arr[i]+= arr[i-1];
        }
        // for(auto a:arr){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        for (int i = 0; i < q; i++)
        {
            ll l,r,k;cin>>l>>r>>k;
            l--,r--;
            ll aux =arr[r]-arr[l]; 
            if((aux/2)+(aux&1)<= k){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
        
    
    }

    return 0;
}