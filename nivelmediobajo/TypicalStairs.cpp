#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    set<ll> st;
    vll arr(n+1);
    for (ll i = 0,a; i < m; i++)
    {
        cin>>a;
        st.insert(a);
    }
    arr[n] = 1;
    for (int i = n-1; i >= 0; i--)
    {
        if(i+1<=n && st.find(i+1) == st.end()){
            arr[i] = (arr[i]+arr[i+1])%MOD;
        }
        if(i+2<=n && st.find(i+2) == st.end()){
            arr[i] = (arr[i]+arr[i+2])%MOD;
        }
    }
    // for(auto a:arr){
    //     cout<<a<<" ";
    // }
    // cout<<"\n";
    cout<<arr[0]<<"\n";
    
    return 0;
}