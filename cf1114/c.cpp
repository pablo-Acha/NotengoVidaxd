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
        string a,b;cin>>a>>b;
        if(n<=2){
            cout<<(a==b?"YES":"NO")<<"\n";
            continue;
        }
        ll impA = 0, impB = 0;
        ll parA = 0, parB = 0;
        for (int i = 0; i < n; i++)
        {
            if(i&1){   
                parA+= (a[i] == '1');
                parB+= (b[i] == '1');
            }else{
                impA+= (a[i] == '1');
                impB+= (b[i] == '1');
            }
        }
        if(parA == parB && impA == impB){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    
    }

    return 0;
}