#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        vector<vll> dp(k,vll(26));
        dp[0][s[0]-'a'] = 1;
        // ll com = 0;
        set<ll> st;
        ll com = s[0]-'a';
        st.insert(com);
        vector<unordered_set<ll>> atras(26);
        for (int i = 1; i < k; i++)
        {
            if(i<n){
                ll act = s[i]-'a';
                ll post = s[i-1]-'a';
                st.insert(act);
                atras[act].insert(post);
            }
            
            for(auto x:st){
                ll res = 0;
                for (ll j = 0; j < 26; j++)
                {
                    if(x == com || atras[x].count(j)>0){
                        res= (res+ dp[i-1][j])%MOD;
                    }    
                }
                dp[i][x]= res;
                
            }
        }
        // for(auto v:dp){
        //     for(auto x:v)cout<<x<<" ";cout<<"\n";
        // }
        ll res = 0;
        for (int i = 0; i < 26; i++)
        {
            res= (res +dp[k-1][i])%MOD;
        }
        cout<<res<<"\n";
        
    }

    return 0;
}