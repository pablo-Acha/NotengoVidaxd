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
        ll n;cin>>n;
        vector<string> vs(2);
        for (int i = 0; i < 2; i++)
        {
            cin>>vs[i];
        }
        bool f= 1;
        for (int i = 0; i < n; i++)
        {
            if(vs[0][i] == vs[1][i] && vs[0][i] == '.'){
                vs[0][i] = '4';
                vs[1][i] = '3';
                // cout<<i<<"\n";
            }else if(i<n-1){
                if(vs[0][i] == vs[0][i+1] && vs[0][i] == '.'){
                    vs[0][i] = '1';
                    vs[0][i+1] = '2';
                }else if(vs[0][i] == '.'){
                    f = 0;
                    break;
                }
                if(vs[1][i] == vs[1][i+1] && vs[1][i] == '.'){
                    vs[1][i] = '1';
                    vs[1][i+1] = '2';
                }else if(vs[1][i] == '.'){
                    f = 0;
                    break;
                }
            }
        }
        // for (int i = 0; i < 2; i++)
        // {
        //     cout<<vs[i]<<"\n";
        // }
        
        bool unique = 1;
        for (int i = 0; i < n; i++)
        {
            if(vs[1][i] == '.' || vs[0][i] == '.'){
                f =0;
                break;
            }else{

                if(vs[0][i] == vs[0][i+1] && vs[0][i]!='#' || vs[1][i] == vs[0][i] && vs[0][i]!='#'
                ||vs[1][i] == vs[1][i+1] && vs[1][i]!='#'){
                    unique = 0;
                }

            }
        }
        if(f){
            cout<<(unique?"Unique\n":"Multiple\n");
        }else{
            cout<<"None\n";
        }
        
    }

    return 0;
}