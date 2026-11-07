#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--) {
        ll n, k;
        cin>>n>>k;
        k = min(n,k);
        

        ll j = 0;
        while (j+1<63 &&((1LL<<(j+1))-1)*k <= n) {
            j++;
        }

        ll aux = n - (((1LL << j) - 1) * k);
        ll x = (1LL << j) - 1;
        ll res = 0;     
        while(aux>=(1LL<<j)){
            res++;
            aux-= 1LL<<j;
        }

        res += __builtin_popcountll(x) * k;
        // cout<<j<<" "<<aux2<<"\n";
        cout<<res<< '\n';
    }
}