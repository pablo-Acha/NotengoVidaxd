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
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        if(n/2<k){
            cout<<"-1\n";
            continue;
        }
        ll cnt = 0;
        for (int i = 0; i < k; i++)
        {
            if(s[i] == 'L')cnt++;
        }
        for (int i = n - 1; i >= n-k; i--)
        {
            if(s[i] == 'R')cnt++;
        }
        cout<<cnt<<"\n";
        //   vll arr(n);for(auto &a:arr)cin>>a;
    
    }

    return 0;
}