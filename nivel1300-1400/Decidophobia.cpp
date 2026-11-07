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
        ll n,d;cin>>n>>d;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll no = 0;
        ll aux = 0;
        for (int i = 0; i < d; i++)
        {
            aux += arr[i];
        }
        vll pref(n),suf(n);
        ll tem = aux;
        for (int i = d,j = 0; j<n; i = (i+n+1)%n,j++)
        {
            pref[i] = aux;
            aux= aux+arr[i]-arr[(i-d+n)%n]; 
        }
        aux= tem;
        for (int i = n-1,j = 0; j < n; i = (i-1+n)%n, j++)
        {
            suf[i] = aux;
            aux = aux+arr[i]-arr[(i+d)%n];
        }

        ll res = 0;
        vll td(n);
        // for(auto x:suf)cout<<x<<" ";cout<<"\n";
        // for(auto x:pref)cout<<x<<" ";cout<<"\n";
        for (int i = 0; i < n; i++)
        {
            no += td[i];
            if(arr[i]*2*d>suf[i]+pref[i]){
                // cout<<i<<" "<<(arr[i]*(2*d))-(suf[i]+pref[i])<<"\n";
                res+= (arr[i]*(2*d))-(suf[i]+pref[i]);
                no++;
                td[(i+d+1)%n]--;
                td[(i-d+n)%n]++;
            }    
            // for(auto x:td)cout<<x<<" ";cout<<"\n"; 
        }
        cout<<res<<"\n";

    }
    

    return 0;
}