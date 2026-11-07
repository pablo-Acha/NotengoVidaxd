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
    while(t--)
    {   
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        ll res = 0;
        bool f = 1;
        for (int i = 0; i < n-1; i++)
        {
            ll mn = 1e9, ind = 1e9;
            for (int j = i; j < n; j++)
            {
                // cout<<arr[j]<<" "<<brr[i]<<"\n";
                if(arr[j]<=brr[i]){
                    ind = j;
                    mn = arr[j];
                    break;
                }
            }
            if(mn == 1e9){
                f = 0;
                // cout<<i<<" "<<ind<<" "<<mn<<"\n";
                break;
            }
            for (int j = ind; j >= i+1; j--)
            {
                res++;
                swap(arr[j],arr[j-1]);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>brr[i]){
                f = 0;
                break;
            }
        }
        if(!f){
            cout<<-1<<"\n";
        }else{
            cout<<res<<"\n";
        }
        
    }
    return 0;
}