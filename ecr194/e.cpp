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
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += arr[i] == 0;
        }
        if(cnt<2){
            cout<<"-1\n";
        }else{
            ll res = (arr[0] == 1)+(arr[n-1] == 1);
            cout<<res<<"\n";
        }
    }

    return 0;
}