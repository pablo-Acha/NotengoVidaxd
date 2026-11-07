#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n,x;cin>>n>>x;
        vector<pair<ll,ll>> vpp(n);
        for (ll i = 0,a,b,c; i < n; i++)
        {
            cin>>a>>b>>c;
            vpp[i].first = (a*(b-1))+(a-c);
            vpp[i].second = (a*(b-1));
        }
        ll gratis = 0;
        for (int i = 0; i < n; i++)
        {
            gratis+= vpp[i].second;
        }
        sort(vpp.begin(),vpp.end());
        if(gratis>= x){
            cout<<0<<rnl;
        }else if(gratis< x && vpp[n-1].first<=0){
            cout<<-1<<rnl;
        }else{
            ll val = 0;
            for (int i = 0; i < n; i++)
            {
                val+= vpp[i].second;
            }
            // cout<<val<<" ";
            ll sub = x-val;
            if(sub<=0){
                cout<<0<<rnl;
            }else{
                ll res = (sub/vpp[n-1].first) + (sub%vpp[n-1].first>0);
                // if((res*vpp[n-1].first) +vpp[n-1].second < sub){
                //     res++;
                // }
                cout<<res<<rnl;
                
            }
        }
        
        
        
    }
    
    return 0;
}