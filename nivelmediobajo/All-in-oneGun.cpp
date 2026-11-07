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
        ll n,h,k;cin>>n>>h>>k;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll s = accumulate(all(arr),0LL);
        if(h%s == 0){
            cout<<((h/s) *n ) + ((h/s - 1 )* k)<<"\n";
        }else{
            ll res = ((h/s)*n) + ((h/s) * k);
            // ll val = 0;
            ll hh = h%s; 
            // cout<<res<<"\n"<<hh<<"\n";
            for (int i = 0; i < n ; i++)
            {   
                if(hh-arr[i]<=0){
                    // cout<<i<<"*----\n";
                    if(i == 0){
                        res++;
                        break;
                    }
                    ll mx = *max_element(arr.begin()+i,arr.end());
                    vll pre(i);
                    for (int j = 0,r = i-1; j < i; j++,r--)
                    {
                        pre[j] = arr[r]+(j>0?pre[j-1]:0);
                    }
                    mx-=hh;
                    ll p = upper_bound(all(pre),mx)-pre.begin();
                    // cout<<i<<" "<<p<<"\n";   
                    ll mn =  i-p>0?*min_element(arr.begin(),arr.begin()+i-p):1e18;
                    if((mx- (p>0?pre[p-1]:0))>=mn)p++;
                    
                    res += i-p+1;
                    break;
                }
                hh-=arr[i];
            }
            
            cout<<res<<"\n";
        }
        
    }

    return 0;
}