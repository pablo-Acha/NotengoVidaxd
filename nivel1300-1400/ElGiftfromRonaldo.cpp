// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef vector<ll> vll;

// ll guas(ll n) { return n * (n + 1) / 2; }

// const ll MOD =998244353;
// ll modpow(ll a, ll b){
//     ll res = 1;
//     while(b){
//         if(b&1) res = res*a%MOD;
//         a = a*a%MOD;
//         b >>= 1;
//     }
//     return res;
// }
// ll C(int n, int x){
//     x = min(x, n - x);

//     ll num = 1;
//     ll den = 1;

//     for(int i = 1; i <= x; i++){
//         num = num * (n - x + i) % MOD;
//         den = den * i % MOD;
//     }

//     return num * modpow(den, MOD - 2) % MOD; 
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     ll s,n,k;cin>>s>>n>>k;
//     ll res = n/s;
//     set<ll> st;

//     for (int i = 0; i <k; i++)
//     {
//         ll a;cin>>a;
//         st.insert(a);
//     }
//     vll pos;
//     for(auto a:st){
//         res-= n/lcm(a,s);
//         for (int i = 0; i < pos.size(); i++)
//         {
//             res+= n/lcm(lcm(a,s),pos[i]);
//         }
        
//         pos.push_back(a);
//     }
        

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a (50);
    for (int i = 1; i <= 50; i++)
    {
        a[i-1] = i;
    }
    

    map<int,int> mx;

    for (int x : a) {
        map<int,int> cnt;

        int y = x;
        for (int p = 2; p * p <= y; p++) {
            while (y % p == 0) {
                cnt[p]++;
                y /= p;
            }
        }
        if (y > 1) cnt[y]++;

        for (auto [p,e] : cnt)
            mx[p] = max(mx[p], e);
    }

    vector<int> ans;

    for (auto [p,e] : mx) {
        while (e--)
            ans.push_back(p);
    }

    for (int x : ans)
        cout << x << ' ';
}