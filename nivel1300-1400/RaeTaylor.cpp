#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        set<ll> st;
        vector<vll> grafo(n+1);
        for (int i = 0; i < n; )
        {
            ll a = arr[i];
            ll mx = 0;i++;
            while(i<n && arr[i]>a){
                grafo[a].push_back(arr[i]);
                mx = max(arr[i],mx);
                i++;
            }
            ll cnt = 0;
            for(auto x:st){
                if(x<mx){
                    cnt++;
                    grafo[mx].push_back(x);
                }else{
                    break;
                }
            } 
            for (int i = 0; i < cnt; i++)
            {
                st.erase(st.begin());
            }     
            if(a!=1)st.insert(a);
        }
        if(st.empty()){
            cout<<"YES\n";
            for (int i = 1; i <= n; i++)
            {
                for(auto x:grafo[i]){
                    cout<<i<<" "<<x<<"\n";
                }
            }
            
        }else{
            cout<<"NO\n";
        }   
    }   
    
    return 0;
}