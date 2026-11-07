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
        string s;cin>>s;
        string c;cin>>c;
        ll a  = 0,b = 0,p = 0;
        ll ce = 0, un = 0;
        for (int i = 0; i < n; i++)
        {
            ce+=s[i] == '0';
            un+=s[i] == '1';
        }
        a = ce*un;ce = 0,un = 0;
        for (int i = 0; i < n; i++)
        {
            ce+=c[i] == '0';
            un+=c[i] == '1';
        }
        b = ce*un;ce = 0,un = 0;
        string x = "";
        for (int i = 0; i < n; i++)
        {
            if(s[i]!=c[i]){
                x.push_back('1');
            }else{
                x.push_back('0');
            }
        }
        for (int i = 0; i < n; i++)
        {
            ce+=x[i] == '0';
            un+=x[i] == '1';
        }
        p = ce*un;
        ll res = (((1LL<<k) +1 )/3)*(a+b+p) + (!(k&1)?a+b:0);
        cout<<res<<"\n";
        
    }
    

    return 0;
}