#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll gaus(ll n){
    return (n*(n+1))/2;
}

struct Punto{
    ll x;
    ll y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        ll l = 0 ,r = 20000,mid = 0;
        while(l<=r){
            mid = (l+r)/2;
            if(gaus(mid)<= y+x){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        Punto P = {x,gaus(r)-x};  
        Punto Q = {gaus(r)-y,y};

        ll suma_x = P.x + Q.x; 

        ll x_res;
        if (suma_x >= 0) {
            x_res = (suma_x + 1) / 2; 
        }

        ll y_res = gaus(r) - x_res;

        Punto medio = {x_res, y_res};
        if(medio.x <0){
            medio = {0,gaus(r)};
        }else if(medio.y<0){
            medio = {gaus(r),0};
        }
        string s = "";
        ll k= r;
        cout<<medio.x<<" "<<medio.y<<"\n";

        ll target_p = medio.x;

        for (ll w = r; w >= 1; w--) {
            if (target_p >= w) {
                s += 'X';
                target_p -= w;
            } else {
                s += 'Y';
            }
        }
        cout<<s<<"\n";
        s = "YYYYYYYYYYYYY";
        ll a = 0,b = 0;
        ll ox = 0,oy = 0;
        for (int i = 0,j = s.size()-1; i < s.size(); i++,j--)
        {
            if(s[i] == 'Y'){
                b++;
            }else{
                a++;
            }
            ox+= a;
            oy += b;
        }
        cout<<ox<<" "<<oy<<"\n";
        cout<<"\n";
        
        

    }

    return 0;
}