
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(ll mid, ll x, vll& arr){
    ll n = arr.size();
    vll aux;

    for (int i = 0; i < n; i++)
    {
        bool f = 0;
        if(i > 0 && arr[i]-arr[i-1] <= mid)
        { 
            f = 1;
        }
        if(i+1 < n && arr[i+1]-arr[i] <= mid) f = 1;
        if(!f) aux.push_back(arr[i]);
    }
    ll cnt = 0;
    for (int i = 0; i < aux.size(); i++)
    {
        if(i+1 < aux.size() &&
           aux[i+1]-aux[i] <= 2*mid){
            i++;
        }
        cnt++;
    }
    return cnt <= x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,x;cin>>n>>x;
        vll arr(n);
        for(auto &a:arr)cin>>a;

        ll l = 1,r = 1e9,mid = 0;

        while(l<=r){
            mid = (l+r)/2LL;
            if(fun(mid,x,arr)){
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        cout<<l<<"\n";
    }

    return 0;
}
