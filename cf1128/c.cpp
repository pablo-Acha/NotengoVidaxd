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
        ll n;cin>>n;
        ll par = 0,imp = 0;
        for (int i = 0; i < n; i++)
        {
            ll a;cin>>a;
            if(a&1){
                imp++;
            }else{
                par++;
            }
        }
        ll comp = (imp/2 || (par>0))+(imp&1);
        if(comp == 1){
            cout<<"Moggity\n";
        }else{
            ll aux = par+(imp/2);
            if(aux>1){
                cout<<"Moggity\n";
            }else{
                cout<<"Larpity\n";
            }
        }


    }
    

    return 0;
}