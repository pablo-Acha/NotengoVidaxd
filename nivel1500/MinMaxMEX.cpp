#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(ll mid, vll &arr,ll k){

    ll n = arr.size();
    ll cnt = 0;
    unordered_set<ll> st;
    
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<mid)st.insert(arr[i]);       
        if(st.size() == mid){
            cnt++;
            st.clear();                 
        }
    }
    return cnt>=k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll l = 0,r = n/k,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(fun(mid,arr,k)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        cout<<r<<"\n";
        // cout<<fun(5,arr,k)<<"\n";
    }

    return 0;
}