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
        vll brr;
        brr.push_back(arr[0]);
        ll res = 0;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]==arr[i-1]){
                res++;
                continue;
            }
            brr.push_back(arr[i]);
        }  
        // for(auto a:brr)cout<<a<<" ";
        // cout<<"\n"; 
        for (int i = 1; i < brr.size(); i++)
        {
            if(brr[i] < brr[i-1]){
                ll aux=0;
                while (i<brr.size() && brr[i] < brr[i-1])
                {
                    aux++;
                    i++;
                }
                aux--;
                i--;
                res+=aux;
            }else{
                ll aux=0;
                while (i<brr.size() && brr[i] > brr[i-1])
                {
                    aux++;
                    i++;
                }
                aux--;
                i--;
                res+=aux;
            }   
        }
        
        cout<<n-res<<"\n";
    }
    return 0;
}