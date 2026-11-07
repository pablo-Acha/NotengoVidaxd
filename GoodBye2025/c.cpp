#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll pref(n),suff(n);
        pref[0]= arr[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = (arr[i]<0?arr[i]*-1:arr[i]) +pref[i-1];
        }
        suff[n-1] = arr[n-1]*-1;
        for (int i = n - 2; i >= 0; i--)
        {
            suff[i] = suff[i+1] +(arr[i]*-1);
        }
        ll mx = -1e18;
        for (int i = 1; i < n-1; i++)
        {
            ll val = pref[i-1]+suff[i+1];
            mx = max(val,mx);
        }
        // for(auto a:pref)cout<<a<<" ";
        // cout<<endl;
        // for(auto a:suff)cout<<a<<" ";
        // cout<<endl;
        mx = max(mx, max(suff[1],pref[n-2]));
        cout<<mx<<endl;
    }
    return 0;
}