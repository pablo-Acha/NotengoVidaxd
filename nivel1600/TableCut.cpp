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
        ll n,m;cin>>n>>m;
        vll acc(n); 
        ll xi = 0;
        vector<vll> arr(n,vll(m));for(auto &v:arr){for(auto &a:v){cin>>a;} acc[xi] = accumulate(all(v),0LL); acc[xi] += xi!=0?acc[xi-1]:0;xi++;}
        ll mitad = acc[n-1]/2;
        // for(auto a:acc)cout<<a<<" ";
        // cout<<"\n";
        int i = 0;
        ll res = mitad *(mitad+(acc[n-1]&1));
        cout<<res<<"\n";
        ll sum = 0;
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if(f)for (int j = m - 1; j >= 0; j--)
            {
                sum += arr[i][j];
                if(sum >= mitad){
                    f=0;
                    for (int h = 0; h < m; h++)
                    {
                        if(h == j){cout<<"D";i++;}
                        cout<<"R";                        
                    }
                    break;
                }
            }
            if(i<n)cout<<"D";
        }
        cout<<"\n";
        
    }

    return 0;
}