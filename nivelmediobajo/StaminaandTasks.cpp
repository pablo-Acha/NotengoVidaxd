#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<double> c(n),p(n);
        for (int i = 0; i <n; i++)
        {
            cin>>c[i]>>p[i];
        }
        double act = c[n-1];
        for (int i = n - 2; i >= 0; i--)
        {
            if(act< c[i]+(act*(1-(p[i]/100))))
            {
                act = c[i]+(act*(1-(p[i]/100)));
            }
        }
        cout<<fixed<<setprecision(9)<<act<<"\n";
    }

    return 0;
}