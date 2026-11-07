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

    ll n;cin>>n;
    string s;cin>>s;
    ll mx = 1LL<<n;
    cout<<mx<<"\n";
    vll arr(mx+1);
    for (int i = 1; i <= mx; i++)
    {
        ll x = i;
        ll xp = mx-i+1;
        bool f = 1;
        for (int j = mx/2,h = 0; h< s.size(); j/=2,h++)
        {
            if(s[h] == '1'){
                x/=2;
                xp=j-x+1;
            }else{
                xp/=2;
                x=j-xp+1;
            }
            if(x == 0 || xp== 0){
                f = 0;
                break;
            }
        }
        if(f)cout<<i<<" ";
    }
    cout<<"\n";
    

    return 0;
}