#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll gaus(ll n){return n*(n+1) /2;}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n); for(auto &a:arr)cin>>a;
        vll cnt(31);
        for (int i = 0; i < n; i++)
        {
            ll h = 0;
            while(arr[i]){
                if(arr[i]&1){
                    cnt[h]++;
                }
                h++;
                arr[i] = arr[i]/2;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            bool f = 1;
            for (int j = 0; j < 31 && f; j++)
            {
                f &=(cnt[j]%i == 0);
            }
            if(f){
                cout<<i<<" ";
            }
        }
        cout<<"\n";
    }   
       
    return 0;
}