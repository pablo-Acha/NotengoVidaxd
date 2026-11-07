#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll div;
        for (int i = 2; i <= sqrt(n) && n>1; i++)
        {
            while (n%i == 0)
            {
                n/=i;
                div.push_back(i);
            }
        }
        if(n>1)div.push_back(n);
        set<ll> st;
        ll acc = 1;
        ll h = 0;
        // for(auto a:div)cout<<a<<" ";
        // cout<<"\n";
        for(auto x:div){
            
            acc*=x;
            if(st.find(acc)==st.end() && h <2){st.insert(acc);acc = 1;h++;}
        }
        if(acc!=1)st.insert(acc);
        // for(auto a:st)cout<<a<<" ";
        // cout<<"\n";
        if(st.size() == 3){
            cout<<"YES\n";
            for(auto a:st){
                cout<<a<<" ";
            }
            cout<<"\n";
        }else{
            cout<<"NO\n";
        }
    }
    return 0;
}