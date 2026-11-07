#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

ll f(deque<ll> brr){
    ll l = 0;
    ll r = 0;
    ll m = brr.size();
    for (int i = 0; i < m; i+=2)
    {
        ll aux = max(abs(brr[i])+l,abs(brr[i+1])+r);
        l= aux;
        r+= brr[i+1];
    }
    return max(l,r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);for(auto &a:brr)cin>>a;
        ll m;cin>>m;
        multiset<ll> ml;
        ll lst = 0;
        for (int i = 0; i < m; i++)
        {
            ll a;cin>>a;
            ml.insert(a);
            lst = a;
        }
        bool f = 0;
        for (int i = 0; i < n && !f; i++)
        {
            if(brr[i] == lst)f = 1;
        }
        if(f){
            for (int i = 0; i < n; i++)
            {
                if(arr[i]!= brr[i]){
                    if(ml.find(brr[i]) == ml.end()){
                        f = 0;
                        break;
                    }else{
                        ml.erase(ml.find(brr[i]));
                    }
                }
            }
            cout<<(f?"YES\n":"NO\n");
        }else{
            cout<<"NO\n";
        }

    }
    
    
    return 0;
}