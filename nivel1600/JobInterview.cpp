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
        ll n,m;cin>>n>>m;
        vll arr(n+m+1);for(auto &a:arr)cin>>a;
        vll brr(n+m+1);for(auto &a:brr)cin>>a;
        vll pref(n+m+1);
        ll wa = n,we= m;
        vll us(n+m+1);
        for (int i = 0; i < n+m; i++)
        {
            if(arr[i]>brr[i] && wa || !we){
                pref[i] = arr[i];
                us[i] = 1;
                wa--;
            }else if(brr[i]>arr[i] && we || !wa){
                pref[i] = brr[i];
                we--;
            }
            if(i>0)pref[i]+=pref[i-1];
        }
        ll sum = pref[n+m-1];
        // cout<<sum<<"\n";
        ll df= 0,df2=0;
        vll res;res.push_back(sum);
        for (int i = n+m-1; i >= 0; i--)
        {
            if(us[i]){
                if(df){
                    res.push_back(sum-arr[i]+df+brr[n+m]);
                }else{
                    res.push_back(sum-arr[i]+arr[n+m]);
                }
                if(brr[i]>arr[i]) df2 = brr[i]-arr[i];
            }else{
                if(df2){
                    res.push_back(sum-brr[i]+df2+arr[n+m]);
                }else{
                    res.push_back(sum-brr[i]+brr[n+m]);
                }
                if(arr[i]>brr[i]) df = arr[i]-brr[i];
            }
        }
        reverse(all(res));
        for(auto x:res)cout<<x<<" ";cout<<"\n";

                
        
    }

    return 0;
}