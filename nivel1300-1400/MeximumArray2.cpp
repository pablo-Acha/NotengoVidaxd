#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n) { return n * (n + 1) / 2; }

const ll MOD =998244353;
ll modpow(ll a, ll b){
    ll res = 1;
    while(b){
        if(b&1) res = res*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    return res;
}
ll C(int n, int x){
    x = min(x, n - x);

    ll num = 1;
    ll den = 1;

    for(int i = 1; i <= x; i++){
        num = num * (n - x + i) % MOD;
        den = den * i % MOD;
    }

    return num * modpow(den, MOD - 2) % MOD; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,k,q;cin>>n>>k>>q;
        vector<pair<ll,ll>> arr;
        vector<pair<ll,ll>> brr;
        for (int i = 0; i < q; i++)
        {
            ll c,a,b;cin>>c>>a>>b;
            a--;b--;
            if(c == 1){
                arr.emplace_back(a,b);
            }else{
                brr.emplace_back(a,b);
            }
        }
        vll res(n,1e5);
        for (int i = 0; i < arr.size(); i++)
        {
            auto [l,r] = arr[i];
            for (int j = l; j <= r; j++)
            {
                res[j] = k;
            }
        }
        sort(brr.begin(),brr.end());
        for (int i = 0; i < brr.size(); i++)
        {
            auto [l,r] = brr[i];
            set<ll> st;
            for (int pr = 0; pr < k; pr++)
            {
                st.insert(pr);
            }
            
            
            for (int j = l; j <= r; j++)
            {
                if(res[j] == k)res[j]++;
                else{
                    if(st.find(res[j]) !=st.end()){
                        st.erase(res[j]);
                    }else if(res[j] == 1e5 && !st.empty()){
                        res[j] = *st.begin();
                        st.erase(st.begin());
                    }
                }

            }
        }
        for(auto a:res)cout<<a<<" ";
        cout<<"\n";
    }
}