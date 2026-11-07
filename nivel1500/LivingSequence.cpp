#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()
ll pre[13];



void init(){
    ll det = 1;
    for (int i = 1; i <= 12; i++)
    {
        pre[i] = (9*pre[i-1]) +det;
        det*=10; 
    }
        
}

ll calcu(ll n){
    ll res = 0;
    deque<ll> dq;
    ll d = 1;
    while(n){dq.push_back(n%10);n/=10;d*=10;}
    d/=10;
    // cout<<d<<"\n";
    // for(auto x:dq)cout<<x<<" ";cout<<"\n";
    for (ll i = dq.size() - 1; i >= 0; i--)
    {
        if(dq[i] == 4){
            res++;
            for (ll j = 0, h = 1; j < i; j++,h*=10)
            {
                res+= h*dq[j];
                dq[j]= 9;   
            }   
            dq[i] = 3;
            i++;      
            continue;   
        }else{
            if(dq[i]>4){
                res+= d;
            }
            res+=(pre[i]*(dq[i]-(dq[i]>4)));
            // cout<<res<<" "<<i<<" "<<pre[i]<<" "<<dq[i]<<"\n";
        }
        d/=10;
    }
    return res;
    
        
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    // for (int i = 0; i < 12; i++)
    // {
    //     cout<<pre[i]<<" ";
    // }
    // cout<<"\n";
    
    
    ll t;cin>>t;
    while(t--)
    {
        ll n;cin>>n;
        ll res = calcu(n);
        ll base = 0;
        ll x = 5;
            // cout<<res<<" "<<base<<"\n";
        while (res!=base)
        {
            ll m = n+res;
            base = res;
            res = calcu(m);
            // cout<<res<<" "<<base<<" "<<m<<"\n";
        }
        cout<< n+res<<"\n";
    }

    return 0;
}