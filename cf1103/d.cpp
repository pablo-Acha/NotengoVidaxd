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
    while(t--)
    {   
        ll n,k;cin>>n>>k;
        vll arr(n+1);
        vll brr;
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            arr[a]++;
            st.insert(a);
        }
        bool f = 0;
        for(auto a:st){
            brr.push_back(a);
        }
        // for(auto a:brr)cout<<a<<" ";
        // cout<<"\n";

        for (int i = n; i >0; i--)
        {
            if(arr[i] == 0)continue;
            if(arr[i]%2 == 0){f = 1;continue;}
            ll ma = lower_bound(brr.begin(),brr.end(),i)-brr.begin();
            ll men = lower_bound(brr.begin(),brr.end(),(i-k))-brr.begin();
            // cout<<i<<" "<<ma<<" "<<men<<"\n";
            if(ma > men){f = 1;break;}

        }
        
        
        cout<<(f?"YES\n":"NO\n");        
        

        
    }
    return 0;
}