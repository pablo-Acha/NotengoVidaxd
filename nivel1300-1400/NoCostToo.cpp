#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    vector<vll> primos(2e5+11);
    vll vis(2e5+10);
    for (ll i = 2; i <2e5+10; i++)
    {
        if(vis[i])continue;
        primos[i].push_back(i);
        for (ll j = i+i; j < 2e5+10; j+=i)
        {
            vis[j] = 1;
            primos[j].push_back(i);
        }
    }
    // for (int i = 0; i < primos.size(); i++)
    // {
    //     cout<<i<<": ";
    //     for(auto x:primos[i])cout<<x<<" ";
    //     cout<<"\n";
    // }
    
    while(t--){
        ll n;cin>>n;
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &a:brr)cin>>a;
        
        ll p = 0;
        for (int i = 0; i < n; i++)
        {
            p+=(arr[i]%2 == 0);
        }
        if(p>=2){
            cout<<0<<"\n";
        }else{
            sort(arr.begin(),arr.end());
            set<ll> com;
            bool f = 0;
            bool f1 = 0;
            for (int i = 0; i < n && !f; i++)
            {

                for(auto x:primos[arr[i]]){
                    if(com.find(x) != com.end()){
                        f = 1;
                        // cout<<i<<" "<<x<<" cxx\n";

                        break;
                    }else{
                        com.insert(x);
                    }
                }
                
            }
            set<ll> cm1,cm2;
            for (int i = 0; i < n && !f1; i++)
            {

                for(auto x:primos[arr[i]]){
                    if(cm1.find(x) != cm1.end()){
                        f1 = 1;
                        // cout<<i<<" "<<x<<" cxx\n";

                        break;
                    }else{
                        cm2.insert(x);
                    }
                }
                for(auto x:primos[arr[i]+1]){
                    if(cm2.find(x) != cm2.end()){
                        f1 = 1;
                        // cout<<i<<" "<<x<<" cxx\n";

                        break;
                    }else{
                        cm1.insert(x);
                    }
                }
            }
            if(f){
                cout<<"0\n";
            }else if(f1 || p == 1){
                cout<<"1\n";
            }else{
                cout<<"2\n";
            }
        }
    }
    return 0;
}