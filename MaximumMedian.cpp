#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool f(vll &arr, ll mid, ll k){
    ll n = arr.size();
    ll min = 0;
    for (int i = n/2; i < n; i++)
    {
        ll aux= max(mid-arr[i],0LL); 
        min += aux;
    }
    return min<=k;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k;cin>>n>>k;
    vll arr(n);
    for(auto &a:arr)cin>>a;
    sort(all(arr));
    ll l = 1,r = 1e10,mid = 0;
    while(l<=r){
        mid = (l+r)/2;
        if(f(arr,mid,k)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<r<<"\n";
    return 0;
}