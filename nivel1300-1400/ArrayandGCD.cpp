#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    vll primos;
    vll vis(6e6+1);
    for (ll i = 2; i <= 6e6; i++)
    {
        if(vis[i])continue;
        primos.push_back(i);
        for (ll j = i*i; j <= 6e6; j+=i)
        {
            vis[j] = 1;       
        }
    }
    ll m = primos.size();
    // cout<<m<<"\n";
    while(t--){
        ll n;cin>>n;
        deque<ll> arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        ll j = 0;
        ll es = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr.back()>=primos[j]){
                es += arr.back()-primos[j];
                j++;
            }else{
                arr.push_front(arr.back());
            }
            arr.pop_back();
        }    
        sort(arr.begin(),arr.end());
        while(!arr.empty() && arr.back()+es>=primos[j]){
            es  = arr.back()+es - primos[j];
            j++;
            arr.pop_back();
        }
        cout<<arr.size()<<"\n";
    }
    
    return 0;
}