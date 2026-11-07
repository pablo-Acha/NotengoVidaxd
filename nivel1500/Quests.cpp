#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool f(ll mid, vll& arr, ll d, ll c){
    ll n= arr.size();
    ll k = mid+1;
    ll res = 0;
    for (int i = 0; i < d; i++)
    {
        if(i%k<n){
            res+= arr[i%k];
        }        
    }
    return res>=c;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,c,d;cin>>n>>c>>d;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(all(arr),greater<ll>());
        ll l = 0,r = d-1, mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(f(mid,arr,d,c)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        if(r<0){
            cout<<"Impossible\n";
        }else if(r >=d-1){
            cout<<"Infinity\n";
        }else{
            cout<<r<<"\n";
        }
    }    

    return 0;
}