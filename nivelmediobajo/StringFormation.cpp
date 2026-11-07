#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}
bool f(ll x, ll p){
    if((x == 1 && !(p&1)) || (x == 2 &&(p&1))){
        return 1;
    }
    return 0;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;cin>>s;
    ll q;cin>>q;
    ll p = 0;
    for (int i = 0,a; i < q; i++)
    {
        cin>>a;
        if(a == 1){
            p++;
        }else{
            ll x;cin>>x;
            char c;cin>>c;
            if(f(x,p)){
                s = c+s;
            }else{
                s.push_back(c);
            }
        }
    }
    if(p&1){
        reverse(s.begin(),s.end());
    }
    cout<<s<<"\n";
    return 0;
}