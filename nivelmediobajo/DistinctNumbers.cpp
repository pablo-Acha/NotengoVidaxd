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
    ll n;cin>>n;
    set<ll> st;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        st.insert(a);
    }
    cout<<st.size()<<"\n";
        
    return 0;
}