#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll n,k;cin>>n>>k;
    vll arr(n);for(auto &a:arr)cin>>a;
    deque<ll> dq;
    set<ll> st;
    for (int i = 0; i < n; i++)
    {
        if(st.find(arr[i]) == st.end()){
            if(dq.size() == k){
                ll a = dq[k-1];
                st.erase(st.find(a));
                dq.pop_back();
            }
            dq.push_front(arr[i]);
            st.insert(arr[i]);
        }
    }
    cout<<dq.size()<<"\n";
    for(auto a:dq){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}