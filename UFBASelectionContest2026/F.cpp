#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n;

    vector<ll> ii, ip, pp, pi;


    for (ll i = 0; i < n; i++)
    {
        ll a,b; cin>>a>>b;
        if(a % 2 == 0 && b % 2 ==0){
            pp.push_back(i+1);
        }
        if(a % 2 != 0 && b % 2 !=0){
            ii.push_back(i+1);
        }
        if(a % 2 == 0 && b % 2 !=0){
            pi.push_back(i+1);
        }
        if(a % 2 != 0 && b % 2 ==0){
            ip.push_back(i+1);
        }
    }
    if(ii.size() >= 2){
        cout<<ii[0] <<" "<<  ii[1];
        return 0 ;
    }
    
    if(pi.size() >= 2){
        cout<<pi[0] << " "<<pi[1];
        return 0 ;
    }
    
    if(ip.size() >= 2){
        cout<<ip[0] << " "<<ip[1];
        return 0 ;
    }
    
    if(pp.size() >= 2){
        cout<<pp[0] << " "<<pp[1];
        return 0 ;
    }

    cout<<-1;
    
    return 0;
}