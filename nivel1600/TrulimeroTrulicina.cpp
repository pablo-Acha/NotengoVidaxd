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
        ll n,m,k;cin>>n>>m>>k;
        vector<vll> res(n,vll(m));
        if(n%k == 0){

            for (int i = 0; i < m; i++)
            {
                for (int j = 0,h = i; j < n; j++,h++)
                {
                    res[j][i] = (h%k) + 1;
                }
            }
            
        }else if(m%k == 0){
            for (int i = 0; i < n; i++)
            {
                for (int j = 0,h = i; j < m; j++,h++)
                {
                    res[i][j] = (h%k) + 1;
                }
            }
        }else{

            ll a = gcd(n,k);
            ll b = gcd(m,k/a);
            // ll r = gcd(a,b);
            // cout<<a<<" "<<b<<"\n";
            // a/=r;b/=r;
            // ll x = 1;
            // cout<<r<<"\n";
            // for (int i = 2; i*i <= r; i++)
            // {

            //     while(r%i == 0)
            //     {
            //         if(x&1){
            //             a*= i;
            //         }else{
            //             b*=i;
            //         }
            //         x++;
            //         r/=i;
            //     }               
                
            // }
            // if(r!=1)if(x&1)a*=r;else b*=r;
            

            for (int i = 0; i < n; i+=a)
            {
                for (int j = 0; j < m; j+=b)
                {
                    ll cnt = 1;
                    for (int y = 0; y < a; y++)
                    {
                        for (int x = 0; x < b; x++,cnt++)
                        {
                            res[y+i][j+x] = cnt;
                        }
                    }                    
                }              
            }
        }  
        for(auto v:res){
            for(auto x:v)cout<<x<<" ";cout<<"\n";
        }
    }

    return 0;
}