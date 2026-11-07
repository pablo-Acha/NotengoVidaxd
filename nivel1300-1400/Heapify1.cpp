#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n+1);
        for (int i = 1; i <= n ; i++)
        {
            cin>>arr[i];
        }
        vll vis(n+1);
        for (int i = 1; i <= n/2; i++)
        {
            if(vis[i])continue;
            set<ll> st;            
            for (int j = i; j <= n; j*=2){
                st.insert(arr[j]);
                vis[j] = 1;
            }
            for (int j = i; j <= n; j*=2){
                arr[j] = *st.begin();
                st.erase(st.begin());
            }
        }
        bool f = 1;
        for (int i = 2; i <= n; i++)
        {
            if(arr[i]<arr[i-1]){f = 0;break;}
        }
        cout<<(f?"YES\n":"NO\n");
        
        
    }
    return 0;
}