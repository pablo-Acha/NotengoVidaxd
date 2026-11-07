#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool f(ll mid, vll &pre, vll &suf){
    ll n = pre.size();
    for (int i = 0; i < n ; i++)
    {
        if(i+mid<n && pre[i]+1>= suf[i+mid]){
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;cin>>n>>m;
    string s,t;cin>>s>>t;
    ll l = 1,r = n,mid;
    vll pre(n,-1),suf(n,n);
    ll j = 0;
    for (int i = 0; i < n; i++)
    {
        if(i>0)pre[i] = pre[i-1];
        if(j<m && s[i] == t[j]){
            pre[i] =j;
            j++;
        }
    }
    j = m-1;
    for (int i = n - 1; i >= 0; i--)
    {
        if(i<n-1)suf[i] = suf[i+1];
        if(j>=0 &&s[i] == t[j]){suf[i] = j;j--;}
    }
    // for(auto x:pre)cout<<x<<" ";cout<<"\n";
    // for(auto x:suf)cout<<x<<" ";cout<<"\n";
    while(l<=r){
        mid = (l+r)/2;    
        if(f(mid,pre,suf)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<r<<"\n";
    return 0;
}