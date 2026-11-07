#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}
struct Node{
    ll w;
    ll x;
    ll ind;
    bool operator<(const Node& other) const {
        return w < other.w;
    }
};
struct Node1{
    ll x;
    ll ind;
    bool operator<(const Node1& other) const {
        return x < other.x; 
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        multiset<ll> st;
        for(auto a:arr)
        {
            auto p = st.lower_bound(a/m);
            if((p != st.end()) && (*p ) == a/m &&(a%m == 0 )){
                st.erase(p);
            }else{
                st.insert(a);
            }
        }
        cout<<st.size()<<"\n";
    }

    return 0;
}