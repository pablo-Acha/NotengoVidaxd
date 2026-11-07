#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool pot(ll x){
    if(x == 2)return false;
    while (x%2 == 0)
    {
        x/=2;    
    }
    // cout<<x<<"---\n";
    return x == 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll ini = 1;
        vll aux;

        ll temp = n;
        


        // for(auto x:aux)res.push_back(x);
        ll cnt = 0;
        ll menor = 0;
        while(temp) {
            menor++;
            temp /= 2;
        }


        ll m = 1LL<<menor;

        vll res(m);

        for (int i = 0; i < menor; i++) {
            for (int j = (1LL << i); j < m; j += (1LL << (i+1))) {
                res[j] = 1LL << i;
            }
        }

        vll r;
        r.push_back(0);

        for(int i = 1; i < m; i++) {
            r.push_back(res[i]);
            r.push_back(0);
        }
        
        cout<<r.size()<<"\n";
        for(auto x:r)cout<<x<<" ";cout<<"\n";
    }

    return 0;
}