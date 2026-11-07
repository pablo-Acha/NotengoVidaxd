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
    vll arr,brr;
    arr.push_back(1);
    brr.push_back(3);
    ll aux = 3;
    ll x = 1;
    while (aux<=1e9)
    {
        arr.push_back(aux);
        ll a = aux*3 +(x*(aux/3));
        brr.push_back(a);
        x++;
        aux*=3;
    }
    while(t--)
    {   
        ll n,k;cin>>n>>k;
        ll res = 0;
        ll cnt = 0;
        vll crr(arr.size());
        while(n){
            ll p = upper_bound(arr.begin(),arr.end(),n)-arr.begin();
            p--;
            crr[p]++;
            n-= arr[p];
            cnt++;
        }
        // for(auto a:crr)cout<<a<<" ";
        // cout<<"\n";
        for (int i = crr.size() - 1; i >= 1 && k-cnt>=2; i--)
        {
            if(crr[i] == 0)continue;
            ll he = min((k-cnt)/2,crr[i]);
            crr[i]-=he;
            crr[i-1]+= 3*he;
            cnt+=2*he;
        }
        // for(auto a:crr)cout<<a<<" ";
        // cout<<"\n";
        for (int i = crr.size() - 1; i >= 0; i--)
        {
            res+= brr[i]*crr[i];
            // if(crr[i] == 0)continue;
        }
        
        cout<<(cnt<=k?res:-1)<<"\n";
    }
    return 0;
}