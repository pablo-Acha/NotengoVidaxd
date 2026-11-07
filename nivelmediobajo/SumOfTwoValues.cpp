#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,x;cin>>n>>x;
    vll arr(n);for(auto &a:arr){cin>>a;}
    vll brr(n);
    iota(brr.begin(),brr.end(),1);
    sort(brr.begin(), brr.end(), [&](int i, int j) {
        return arr[i-1] < arr[j-1]; // Comparamos valores de 'a', pero movemos posiciones en 'p'
    });
    sort(arr.begin(),arr.end());
    bool f = 0;
    for (int i = 0; i < n-1; i++)
    {
        if(arr[i]>=x)break;
        ll p = lower_bound(arr.begin()+i+1,arr.end(),x-arr[i])-arr.begin();
        if(p>=n)continue;
        if(arr[i]+arr[p] == x){
            cout<<brr[i]<<" "<<brr[p]<<"\n";
            f = 1;
            break;
        }
    }
    if(!f){
        cout<<"IMPOSSIBLE\n";
    }
    return 0;
}