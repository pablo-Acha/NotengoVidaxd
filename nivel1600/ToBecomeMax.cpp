#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(ll mid,ll k ,vll arr){
    arr.push_back(-1e10);
    ll n= arr.size();
    for (int i = 0; i < n; i++)
    {
        ll acc = 0;
        ll temp = mid;
        for (int j = i; j < n; j++)
        {
            if(arr[j]>=temp)break;
            acc+= temp-arr[j];
            temp--;
        }
        // cout<<acc<<" ";
        if(acc<=k)return true;
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res= *max_element(all(arr));
        ll l = 1,r = 4e8,mid = 0;
        while (l<=r)
        {
            mid = (l+r)/2;
            if(fun(mid,k,arr)){
                l = mid+1;
            }else{
                r = mid-1;
            }         
            // cout<<"\n";
        }
        cout<<r<<"\n";
        
    }

    return 0;
}