#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    ll mn = *min_element(arr.begin(),arr.end());
    ll mx = *max_element(arr.begin(),arr.end());
    ll a = 0,b = 0;
    for (int i = 0; i < n; i++)
    {
        a+= (mn== arr[i]);
        b+= (mx== arr[i]);
    }
    if(mn == mx){
        cout<<mx-mn<<" "<<(n*(n-1))/2<<"\n";
    }else{
        cout<<mx-mn<<" "<<a*b<<"\n";
    }
    return 0;
}