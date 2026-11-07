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
        vll arr(n);for(auto &a:arr)cin>>a;
        bool f = 0;
        ll f1 = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>=2)f1++;
            if(arr[i]>=3){f = true;}
        }
        if(f1>1 || f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}