    #include <bits/stdc++.h>
    using namespace std;

    typedef long long ll;
    typedef vector<ll> vll;
    typedef  pair<int,int> pii;
    typedef  pair<ll,ll> pll;
    typedef  vector<int> vi;

    #define all(x) (x).begin(), (x).end()

    const long long MOD = 1000000007;
    const long long INV2 = 500000004;
    long long gauss(long long n) {
        if(n == 0)return 0;
        n %= MOD;
        return n * ((n + 1) % MOD) % MOD * INV2 % MOD;
    }
    int main() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        ll t;cin>>t;
        while(t--){
            ll n;cin>>n;
            vll arr(n);for(auto &a:arr)cin>>a;
            map<ll,ll> mp;
            mp[0] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                
                ll cur = 0;
                ll cero = mp[0];
                if(mp.find(abs(arr[i])) != mp.end()){
                    cur  = mp[abs(arr[i])]; 
                }
                if(i == 1){
                    cout<<"   "<<cero<<" "<<cur<<"\n";
                }
                cout<<i<<"  -----\n";
                ll aux = cur;
                cur = cero;
                cero = aux;
                mp[0] = (mp[0]+cero)%MOD;
                mp[arr[i]] = (cur+(mp.count(abs(arr[i]))?mp[arr[i]]:0))%MOD;
                for(auto [v,a]:mp){
                    cout<<v<<" "<<a<<"\n";
                }
            }
            // cout<<gauss(0)<<" ";
            // for(auto [v,a]:mp){
            //     cout<<v<<" "<<a<<"\n";
            // }
            cout<<mp[0]<<"\n";
        }

        return 0;
    }