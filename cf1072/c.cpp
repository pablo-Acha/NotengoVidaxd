#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        map<ll,ll> mp;
        priority_queue<int, vector<int>, greater<int>> st;
        st.push(n);
        bool f = 0;
        ll val = 0;
        mp[n] = 0;
        while(!st.empty()){
            auto x = st.top();
            st.pop();
            if(x == k){f = 1;break;}
            ll a = x/2,b = x/2 + (x&1);
            if(mp.find(a)== mp.end()){
                mp[a] = mp[x]+1;
                st.push(a);
            }
            if(mp.find(b)== mp.end()){
                mp[b] = mp[x]+1;
                st.push(b);
            }  
        }
        if(f){
            cout<<mp[k]<<"\n";
        }else{
            cout<<-1<<"\n";
        }
        
    }    
    return 0;
}