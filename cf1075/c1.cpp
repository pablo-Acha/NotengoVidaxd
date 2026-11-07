#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        ll val = 0;
        ll aux = n;
        while(aux){
            val++;
            aux/=2;
        }
        val--;
        // cout<<val<<" ";
        vll res(n);
        ll j = 1;
        ll m = 1<<val;
        // cout<<m<<" ";
        for (ll i = m; i < n; i++)
        {
            res[i] = j;
            j++;
        }
        
        for (int i = 0; i < m; i++)
        {
            res[i] = j;
            j++;
        }
        
        // vll brr;
        // for(auto a:num){
        //     brr.push_back(a);
        // }        
        // cout<<brr.size()<<rnl;
        // for (int i = 0; i < brr.size(); i++)
        // {
        //     res[i] = brr[i];
        // }
        for(auto a:res){
            cout<<a<<" ";
        }
        cout<<rnl;
    }
    
    return 0;
}