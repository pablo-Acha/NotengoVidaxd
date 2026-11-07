#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll r = n-1,l = n-1, acc = 0,res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            acc+=arr[i];
            l = i;
            ll aux  = (r-l+1)*(r+l+2);
            if(aux<= acc){
                acc = 0;
                r = i-1;
            }else{
                res  = max(res,aux-acc);
            }
        }

        ll mx = accumulate(arr.begin(),arr.end(),0LL);
        cout<<res+mx<<"\n";
    }
    
    
    
    return 0;
}