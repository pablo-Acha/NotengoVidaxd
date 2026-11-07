#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool f(ll mid,ll k,vll& arr,vll& brr,vll& crr,vll& sum){
    ll n = arr.size();

    for (int i = 0; i < n; i++)
    {
        ll a = arr[i], b = brr[i], c = crr[i];
        if(sum[i]>=mid)continue;
        if(a == b && b == c)return false;
        if(a<=b && b<=c){
            if(b-a < c-b){
                k-= b-a+1;
                b -= b-a+1;
            }else{
                k-= c-b+1;
                c -= c-b+1;
            }
        }
        k-= mid-(a+b+c);
        if(k<0)return false;
    }
    return true;    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n),brr(n),crr(n),sum(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i]>>brr[i]>>crr[i];
            sum[i] = arr[i]+brr[i]+crr[i];
        }
        ll l = -2e18, r =2e18,mid = 0;
        while(l<=r){
            mid = l+(r-l)/2;
            if(f(mid,k,arr,brr,crr,sum)){
                l = mid+1;
            }else{
                r = mid-1;
            }
            // cout<<mid<<"\n";
        } 
        cout<<r<<"\n";
    }

    return 0;
}