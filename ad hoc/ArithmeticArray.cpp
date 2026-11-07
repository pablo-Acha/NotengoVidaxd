#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll sum= 0;
        for (ll i = 0,a; i < n; i++)
        {
            cin>>a;
            sum+=a;
        }
        if(sum == n){
            cout<<0<<"\n";
        }else if(sum<n){
            cout<<1<<"\n";
        }else{

            cout<<sum-n<<"\n";
        }
    }

    
    return 0;
}