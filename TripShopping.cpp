#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll encontrar(ll x,ll ini,deque<ll> &brr){
    return lower_bound(brr.begin()+ini,brr.end(),8)-brr.begin();
}
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        ll res = 0;
        vector<pair<ll,ll>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i].first;
        }
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i].second;
            if(arr[i].second<arr[i].first){
                swap(arr[i].second,arr[i].first);
            }
            res += arr[i].second-arr[i].first;
        }
        sort(arr.begin(),arr.end());
        bool f = 0;
        ll mx = arr[0].second;
        for (int i = 1; i < n; i++)
        {
            auto [_,a] = arr[i];
            if(a <= mx){
                f = 1;
                break;
            }
            mx = a;
        }
        
        ll mn = 1e10;
        for (int i = 1; i < n; i++)
        {
            if(arr[i].first<=arr[i-1].second){
                f = 1;
                break;
            }
            mn = min(mn,arr[i].first-arr[i-1].second);
        }
        if(f){
            cout<<res<<endl;
        }else{   
            cout<<res+(mn*2)<<endl;
        }

    }
    return 0;
}