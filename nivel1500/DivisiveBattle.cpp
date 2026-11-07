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
    vll primos(1e6+1,1);
    
    for (int i = 2; i < 1e6+1; i++)
    {
        if(!primos[i])continue;
        for (ll j = i*2; j < 1e6+1; j+=i)
        {
            primos[j] = 0;
        }        
    }
    vll igu(1e6+1);
    for (ll i = 2; i < 1e6+1; i++)
    {
        if(primos[i]){
            for (ll j = i*i; j < 1e6+1; j*=i)
            {
                igu[j] = i;    
            }
            
        }
    }
    
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        if(is_sorted(all(arr))){
            cout<<"Bob\n";
            continue;
        }
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            if(primos[arr[i]])continue;
            if(igu[arr[i]]>0){
                arr[i] = igu[arr[i]];
            }else{
                f = 0;
                break;
            }

        }
        // for(auto a:arr)cout<<a<<" ";
        // cout<<f<<"\n";
        if(f){
            if(is_sorted(all(arr))){
                cout<<"Bob\n";
            }else{
                cout<<"Alice\n";
            }
        }else{
            cout<<"Alice\n";
        }     
    }
    

    return 0;
}