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
        ll x,y;cin>>x>>y;
        if(abs(y) <= x + 1){
            ll cnt = 0;
            ll xx = 0, yy = 0;
            while(true){
                if(xx == x&& yy== y)break;
                cnt++;
                if(yy<y){
                    yy++;
                }else{
                    yy--;
                }
                if(xx == x&& yy== y)break;
                xx++;
            }
            cout<<cnt<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }

    return 0;
}