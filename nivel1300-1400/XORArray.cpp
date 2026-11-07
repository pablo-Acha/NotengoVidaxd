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
        ll n,l,r;cin>>n>>l>>r;
        vll arr(n+1 - (r-l+1));
        vll brr(r-l+1);
        for (int i = 0; i <= 28; i++)
        {
            for (int j = 1LL<<i; j < arr.size(); j+=1LL<<i)
            {
                arr[j] += 1LL<<i;
            }
            for (int j = 1LL<<i; j < brr.size(); j+=1LL<<i)
            {
                brr[j] += 1LL<<i;
            }
        }
        brr[0] = brr[brr.size()-1] =(1LL<<29)-1;
        for (int i = 0; i <= 28; i++)
        {
            ll cnt = 0;
            for (int j = 0; j < brr.size(); j++)
            {
                cnt+= ((brr[j]>>i) &1);
            }
            if(cnt&1){
                brr[brr.size()-1]-=(1LL<<i);
            }
        }
        for (int i = 1; i <l;i++)
        {
            cout<<arr[i]<<" ";
        }
        for(auto x:brr)cout<<x<<" ";
        for (int i = l; i <arr.size();i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        
    }

    return 0;
}