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
        s= 'x'+s;
        vll cambio(n+1,0);
        vll L(k);for(auto &x:L)cin>>x;
        vll R(k);for(auto &x:R)cin>>x;
        ll q;cin>>q;
        // cout<<"xxxxxx\n";
        for (int i = 0; i < q; i++)
        {
            ll x;cin>>x;
            ll p = upper_bound(all(L),x)-L.begin()-1;
            // cout<<p<<"\n";
            p = min(L[p]+R[p]-x,x);
            cambio[p]++;
        }
        // cout<<s<<"\n";
        for (int i = 0; i < k; i++)
        {
            ll acc = 0; 
            for (int j = L[i]; j <= (L[i]+R[i])/2; j++)
            {
                acc += cambio[j];
                cambio[j] = acc;
            }
            for (int j = L[i],h = R[i]; j <= (L[i]+R[i])/2; j++,h--)
            {
                if(cambio[j]&1){
                    swap(s[j],s[h]);
                }
            }                        
        }
        for (int i = 1; i < s.size(); i++)
        {
            cout<<s[i];
        }
        cout<<"\n";
    }

    return 0;
}