#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
vll conv(ll n){
    vll arr;
    do{
        arr.push_back(n%10);
        n/=10;
    }while(n);
    reverse(all(arr));
    return arr;
}

ll gaus(ll n){
    if(n<=0) return 0;
    return (n*(n+1))/2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vll arr(17),brr(17);
    // vll crr(16);
    for (ll i = 1,j = 1; i <= 16; i++,j*=10)
    {
        arr[i] = arr[i-1]+(9*j);
        brr[i] = brr[i-1] + (9*i)*j;
    }
    
    
    // for(auto x:arr)cout<<x<<" ";cout<<"\n"; 
    // for(auto x:brr)cout<<x<<" ";cout<<"\n"; 
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        ll p = upper_bound(all(brr),n)-brr.begin()-1;
        // cout<<p<<"\n";
        ll num = arr[p]+((n-brr[p])/(p+1));
        ll r = num + (((n-brr[p])%(p+1))>0);
        // cout<<num<<"\n";
        vll tope = conv(num);
        vll sobre = conv(r);
        ll res = 0;
        for (int i = 0; i < ((n-brr[p])%(p+1)); i++)
        {
            res+= sobre[i];
        }

        ll aux = 1;
        // for(auto x:tope)cout<<x<<" ";cout<<"\n";
        vll crr;crr.push_back(0);
        for (ll i = tope.size() - 1,j = 1,h = 1; i >= 0; i--,j*=10,h++)
        {
            ll temp = gaus(9LL)*j+crr[h-1]*10;
            crr.push_back(temp);
            res += (crr[h-1]*tope[i])+gaus(tope[i]-1)*j + tope[i]*aux;
            aux+= tope[i]*j; 
        }
        // cout<<aux<<"\n";
        // for(auto x:crr)cout<<x<<" ";cout<<"\n";
        cout<<res<<"\n";
        
        
        // cout<<num<<"\n";
    }

    return 0;
}