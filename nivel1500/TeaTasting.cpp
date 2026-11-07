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
        vll arr(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
        }
        vll brr(n+1),pref(n+1);
        
        for (int i = 1; i <= n; i++)
        {
            cin>>brr[i];
            pref[i] = brr[i]+pref[i-1];
        }
        vll res(n+1);
        vll aux(n+1);
        for (int i = 1; i <= n; i++)
        {
            auto p = upper_bound(pref.begin()+i, pref.end(),arr[i]+pref[i-1]);
            if(p != pref.end()){
                auto x = p;
                x--;
                int ind =p-pref.begin(); 
                res[ind] += arr[i]+pref[i-1]-*x;     
                // cout<<ind<<" "<<    arr[i]+pref[i-1]-*x<<"\n";
            }
            p--;
            aux[p-pref.begin()]++;
            aux[i-1]--;
        }
        // for(auto x:pref)cout<<x<<" ";cout<<"\n";
        // for(auto x:aux)cout<<x<<" ";cout<<"\n";
        for (int i = n-1, act = 0; i >= 0; i--)
        {
            aux[i] += aux[i+1];
        }
        // for(auto x:aux)cout<<x<<" ";cout<<"\n";
        for (int i = 1; i <= n; i++)
        {
            res[i]+= brr[i]*aux[i];
            cout<<res[i]<<" ";
        }
        cout<<"\n";        
        // for(auto x:res)cout<<x<<" ";cout<<"\n";

        

    }

    return 0;
}