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

    ll t;cin>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        if(k == 0){
            ll j = 0;
            while(n--){
                if(j&1){
                cout<<"1";
                }else {
                cout<<"0";
                }
                j++;
            }
            cout<<"\n";
            continue;
        }
        ll cer = (k/2)+1;
        ll unos = (k/2)+(k&1)+1;
        if(cer+unos>n){
            cout<<"-1\n";
        }else{
            n-= unos+cer;
            while(cer--){
                cout<<"0";
            }
            while(unos--){
                cout<<"1";
            }
            ll j = 0;
            while(n--){
                if(j&1){
                cout<<"1";
                }else {
                cout<<"0";
                }
                j++;
            }
            cout<<"\n";
        }
    }

    return 0;
}