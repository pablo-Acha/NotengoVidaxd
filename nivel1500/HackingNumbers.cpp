#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll f(ll n){
    ll res = 0;
    cout<<"div "<<n<<"\n";
    cout.flush();
    cin>>res;
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll res;
        cout<<"mul "<<9<<"\n";
        cout.flush();
        cin>>res;
        
        cout<<"digit\n";
        cout.flush();
        cin>>res;
        
        cout<<"digit\n";
        cout.flush();
        cin>>res;
        


        
        cout<<"add "<<n-9<<"\n";
        cout.flush();
        cin>>res;
        
        cout<<"!\n";
        cout.flush();
        cin>>res;
    }
    

    return 0;
}