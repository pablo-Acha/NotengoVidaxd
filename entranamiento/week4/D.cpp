#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool igual(long double a, long double b){
    return abs(a-b)<= 0.1;
}
long double dist(long double x, long double y, long double xx, long double yy ){
    long double sum = abs(x-xx)*abs(x-xx) +abs(y-yy)*abs(y-yy);
    long double mid = sqrt(sum);
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--)
    {
        long double x,y,r;cin>>x>>y>>r;
        long double xx,yy,rr;cin>>xx>>yy>>rr;
        long double k;cin>>k;
        ll d= dist(x,y, xx,yy);
        // cout<<d<<"\n";
        // cout<<(d<=r*r+rr*rr)<<"\n";
        if(k<=r*2 || k<=rr*2 || (d<=r+rr && k<= d+rr+r)){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}