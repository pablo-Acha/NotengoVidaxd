#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(m);for(auto &a:brr)cin>>a;
        vector<bool> b(m);
        sort(arr.begin(),arr.end(),greater<ll>());
        ll k = 0;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if(k>=m || b[k] || k>= arr[i]-1){
                sum += brr[arr[i]-1];
            }else{
                sum+= brr[k];
                b[k] = 1;
                k++;
            }
        }
        cout<<sum<<"\n";
        
    }
    return 0;
}