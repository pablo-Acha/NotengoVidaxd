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
        ll h,w,x,y,xx,yy;cin>>h>>w>>x>>y>>xx>>yy;
        if((abs(y-yy)-1)%2 == 0){
            if(x == xx){
                cout<<"Alice\n";
            }else if(x<xx){

            }else{

            }
        }else{
            if(x == xx){
                cout<<"Bob\n";
            }else if(x<xx){

            }else{
                
            }
        }
    }

    return 0;
}