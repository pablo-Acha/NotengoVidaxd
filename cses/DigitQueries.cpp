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
    vll dp(18);
    ll x = 9;
    for (int i = 1; i <= 17; i++)
    {
        dp[i] = x*i;
        x*=10;  
    }
    
    ll q;cin>>q;
    for (int i = 0; i < q; i++)
    {
        ll n;cin>>n;
        ll acc= 0;
        ll ind = 0;
        ll  aux = 0;
        for (int i = 1; i <=17; i++)
        {
            if(acc+dp[i]>=n){
                n-=acc;
                ind = i;
                break;
            }
            aux += dp[i]/i;
            acc+= dp[i];
        }
        
        ll pos = n%ind;
        ll num = n/ind +aux;
        if(pos == 0){
            cout<<num%10<<"\n";
        }else{
            num++;
            ll temp = ind-pos;
            while(temp--){
                num/=10;
            }
            cout<<num%10<<"\n";
        }
        
    }
    

    return 0;
}