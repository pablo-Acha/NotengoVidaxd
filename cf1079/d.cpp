#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        sort(arr.begin(),arr.end());
        vll val;
        vll cant;
        val.push_back(arr[0]);
        cant.push_back(n);
        for (int i = 1; i < n; i++)
        {
            if(arr[i]!=arr[i-1]){
                val.push_back(arr[i]);
                cant.push_back(n-i);
            }
        }
        ll m = val.size();
        
        vll pref(n);
        pref[0]=brr[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = brr[i]+pref[i-1];
        }
        vll res(m);
        for (int i = 0; i < m; i++)
        {
            ll b = upper_bound(pref.begin(),pref.end(),cant[i])-pref.begin();
            if(b == 0){
                res[i] = 0;
            }else{
                ll aux = val[i] * b;
                res[i] = aux;   
            }
        }
        ll ans = *max_element(res.begin(),res.end());
        cout<<ans<<rnl;            
    }
    
    return 0;
}