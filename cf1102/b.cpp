#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

void ver(string s){
    bool f = 1;
    for (int i = 0,j = s.size()-1; i <= j; i++,j--)
    {
        if(s[i]!=s[j]){
            f = 0;
            break;
        }
    }
    if(f)cout<<s<<"\n";
}
const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n%12 == 10 && n>=22){
            n-= 22;
            cout<<22<<" "<<((n/12)*12)<<"\n";
        }else if(n%12 !=10){
            cout<<n%12<<" "<<((n/12)*12)<<"\n";
        }else{
            cout<<"-1\n";
        }
        // for (int i = 0; i < 100; i++)
        // {
        //     string x = to_string((i*12)+10);
        //     ver(x);
        // }
           
    }
    
    return 0;
}