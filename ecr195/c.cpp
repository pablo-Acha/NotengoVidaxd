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
        vll arr(n);for(auto &x:arr)cin>>x;
        vll aux(k);
        ll act = 0;
        for (int i = 0; i < k; i++)
        {
            act= (act+arr[i])%k;
        }
        ll res = 0;
        ll temp = 0;
        aux[0]++;
        for (int i = k,j = -1; i < n; i++,j++)
        {
            if(j>=0){temp = (temp+arr[j])%k;
            // cout<<temp<<" "<<j<<"\n";
            aux[temp]++;}
            act= (act+arr[i])%k;
            res+= aux[act];
        }
        cout<<res<<"\n";

        
    }

    return 0;
}