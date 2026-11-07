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
        ll n,s,x;cin>>n>>s>>x;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll acc = accumulate(arr.begin(),arr.end(),0LL);
        if(acc>s){
            cout<<"NO"<<"\n";
        }else{
            ll aux = s-acc;
            // cout<<aux<<"*----";
            if(aux%x == 0){
                cout<<"YES"<<"\n";
            }else{
                cout<<"NO"<<"\n";
            }
        }
        
    }
    
    return 0;
}