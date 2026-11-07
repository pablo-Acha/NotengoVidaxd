#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        vll res;
        for (int i = 0,j = n-1; i <= j; i++,j--)
        {
            res.push_back(arr[j]);
            if(i!=j){
                res.push_back(arr[i]);
            }
        }
        reverse(res.begin(),res.end());
        for(auto a:res)cout<<a<<" ";
        cout<<"\n";
    }   
    return 0;
}