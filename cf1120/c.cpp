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
        vll em(2*n);
        for (int i = 0,div = 1; i < n; i++,div++)
        {
            ll l  = arr[i]*div,r = ((arr[i]+1)*div);
            if(l<2*n)em[l]++;
            if(r<2*n)em[r]--;
        }
        ll tem = 0;
        vll res;
        vll aux(2*n,1);
        for (int i = 0; i < n; i++)
        {
            tem+= em[i];
            aux[i] = tem >0;
            if(tem == 0){
                res.push_back(i); 
            }
        }
        for(auto y:aux)cout<<y<<" ";cout<<"\n";
        cout<<res.size()<<"\n";
        for(auto x:res)cout<<x<<" ";cout<<"\n";
    }

    return 0;
}