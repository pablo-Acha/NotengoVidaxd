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
    while (t--)
    {
        ll a,b,c;cin>>a>>b>>c;
        ll act = abs(a-b);
        if(abs(a+c-b)>=act){
            act = abs(a+c-b);
        }
        cout<<act<<"\n";
    }
    

    return 0;
}