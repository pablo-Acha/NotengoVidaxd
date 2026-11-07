#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

const ll MOD = 676767677;
ll guas(ll n){return n*(n+1) /2;}



int main(){
        ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll aux(1e6+10);
        ll mx = 0;
        for (int i = 0; i < n; i++)
        {
            aux[arr[i] -(arr[i]/2)-1]++;
            mx  = max(mx,arr[i] -(arr[i]/2)-1);
        }
        for (int i = mx-1; i >= 0; i--)
        {
            aux[i] += aux[i+1];
        }
        for (int i = 0; i < n; i++)
        {
            aux[arr[i]]++;
        }
        ll res = 0;
        ll unos = 0;
        for (int i = 0; i <= n+10; i++)
        {
            if(aux[i] == 1)unos++;
            if(unos == 2 || aux[i] == 0){res = i;break;}
        }
        cout<<res<<"\n";
    }   
    return 0;
}