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
        vll arr(n);for(auto &a:arr)cin>>a;
        // set<ll> st;
        // vll pos(n+1);
        // st.insert(arr[0]);
        // pos[arr[0]] = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     auto p = upper_bound(all(st),arr[i]);
        //     st.insert(arr[i]);
        //     if(p == st.end()){
        //         pos[arr[i]] = 1;
        //         continue;
        //     }
        //     pos[arr[i]]  = pos[*p]+1;
        // }
        vll lug(n);
        ll mx = 1;
        lug[0] = 1;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]<arr[i-1])mx++;
            lug[i] = mx;
        }
        ll res = 0;
        for (int i = 0; i < n; i++)
        {
            if(i<n-1 && lug[i] == lug[i+1]){
                res+= ((n-1-i+1)*(i+2))-1;
                // cout<<(i+1)*(n-1 - i-1 + 1)*2<<"\n";
                i++;
            }else{
                res += (n-i)*(i+1);
            }
            
            // cout<<res<<"\n";
        }
        cout<<res<<"\n";
        // for(auto x:lug){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
         
    }

    return 0;
}