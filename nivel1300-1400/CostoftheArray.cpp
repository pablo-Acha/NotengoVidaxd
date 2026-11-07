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
    while(t--){
        ll n,k;cin>>n>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll b;
        if(1 == n-k+1){
            for (int i = 1; i < n; i+=2)
            {
                b.push_back(arr[i]);
            }
            b.push_back(0);
            ll res = 0;
            for (int i = 0; i < b.size(); i++)
            {
                if(b[i] !=i+1){
                    res = i+1;
                    break;
                }
            }
            cout<<res<<"\n";   
            continue;         
        }
        bool f = 1;
        for (int i = 1; i <= n-k+1 && f; i++)
        {
            f &= arr[i] == 1;
        }

        if(f){
            cout<<"2\n";
        }else{
            cout<<"1\n";
        }
    }

    return 0;
}