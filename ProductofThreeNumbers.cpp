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
        vll res;
        for (ll i = 2; i*i <= n && 1!=n; i++)
        {
            while(n%i == 0){
                n/=i;
                res.push_back(i);
            }
        }
        if(n!=1)res.push_back(n);
        // for(auto x:res)cout<<x<<" ";cout<<"\n";
        if(res.size()>=3){
        
            vll pref(res.size()),suf(res.size());
            for (int i = 0,j = res.size()-1; i < res.size(); i++,j--)
            {
                pref[i] = res[i]*(i>0?pref[i-1]:1);
                suf[j] = res[j]*(i>0?suf[j+1]:1);
            }
            bool f = 0;
            // for(auto x:pref)cout<<x<<" ";cout<<"\n";
            // for(auto x:suf)cout<<x<<" ";cout<<"\n";
            for (int i = 1; i < res.size()-1; i++)
            {
                if(pref[i-1]!= suf[i+1] && pref[i-1]!=res[i] && res[i]!=suf[i+1]){
                    f = 1;
                    cout<<"YES\n";
                    cout<<pref[i-1]<<" "<<res[i]<<" "<<suf[i+1]<<"\n";
                    break;
                }
            }
            if(!f){
                cout<<"NO\n";
            }
        }else{
            cout<<"NO\n";
        }
        
    }

    return 0;
}