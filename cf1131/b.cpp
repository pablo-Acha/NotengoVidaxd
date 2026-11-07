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
        ll n = 3;
        vll arr(n);
        for(auto &a:arr)cin>>a;
        ll ind = 0;
        ll mx = 0;
        for (int i = 0; i < 3; i++)
        {
            if(arr[(i+1)%3]> arr[(i-1+3)%3]){
                ind = i;
            }
        }
        ll acc = accumulate(all(arr),0LL);
        if(ind == 0){
            for (int i = 0; i < acc; i++)
            {
                cout<<"R";
            }
            
        }else if(ind == 1){
for (int i = 0; i < acc; i++)
            {
                cout<<"S";
            }
        }else{
for (int i = 0; i < acc; i++)
            {
                cout<<"P";
            }
        }
        cout<<"\n";
    }

    return 0;
}