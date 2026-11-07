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
        ll a,b,x;cin>>a>>b>>x;
        vll arr,brr;
        while(true){
            arr.push_back(a);
            if(a == 0)break;
            a/=x;
        }
        while(true){
            brr.push_back(b);
            if(b == 0)break;
            b/=x;
        }
        ll mn = 1e9;
        for (int i = 0; i < brr.size(); i++)
        {
            for (int j = 0; j < arr.size(); j++)
            {
                ll aux = i+j+abs(arr[j]-brr[i]);
                mn = min(aux,mn);
            }   
        }
        cout<<mn<<"\n";
    }
    return 0;
}