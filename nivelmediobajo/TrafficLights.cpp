#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x,n;cin>>x>>n;
    vll arr(n);
    set<ll> st;
    st.insert(0);
    st.insert(x);
    for (ll i = 0,a; i < n; i++)
    {
        cin>>a;
        st.insert(a);
        arr[i] = a;
    }
    ll mx = 0;
    ll ant = 0;
    for(auto a:st){
        if(a>0){
            mx = max(a-ant,mx);
            ant = a;
        }
    }
    vll res;
    res.push_back(mx);
    for (int i = n - 1; i >= 1; i--)
    {
        auto p = st.lower_bound(arr[i]);
        auto be = *prev(p);
        auto af = *next(p);
        mx = max(mx,af-be);
        res.push_back(mx);
        st.erase(p);
    }
    reverse(res.begin(),res.end());
    for(auto a:res){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}