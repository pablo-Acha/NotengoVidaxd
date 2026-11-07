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
    while (t--)
    {
        ll n,k;cin>>n>>k;
        if(k<n || k>2*n-1){
            cout<<"-1\n";
        }else{
            vector<vll> res(n,vll(n));
            ll tam = n;
            ll act  = 1;
            for (int i = 0; i < n; i++,tam--)
            {
                if(k == tam*2){
                    res[i][0] =  act;
                    act++;
                    res[0][i] =  act;
                    act++;
                    k-=2;
                }else{
                    res[i][i] = act;
                    act++;
                    k--;
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if(res[i][j] == 0){
                        res[i][j] = act;
                        act++;
                    }
                    cout<<res[i][j]<<" ";
                }
                cout<<"\n";
            }
            
        }
        
    }
    

    return 0;
}