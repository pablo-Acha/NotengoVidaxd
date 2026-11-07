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
    vll primos;
    vll vis(32000);
    for (ll i = 2; i*i <= 1e9; i++)
    {
        if(vis[i])continue;
        primos.push_back(i);
        for (ll h = i*i; h*h <= 1e9; h+=i)
        {
            vis[h] = 1;
        }
    }
    // cout<<primos.size()<<"\n";
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &x:arr)cin>>x;
        set<ll> p;
        bool f= 0;
        for (int i = 0; i < n && !f; i++)
        {
            for (int j = 0; j < primos.size(); j++)
            {
                if(arr[i]%primos[j] == 0){
                    if(p.find(primos[j])!=p.end()){f = 1;break;}
                    while (arr[i]%primos[j] == 0)
                    {   
                        arr[i]/=primos[j];
                    }
                    p.insert(primos[j]);
                }
            }
        }
        if(f){
            cout<<"YES\n";
        }else{
            set<ll> st;
            for(auto x:arr){
                if(x != 1)
                {
                    if(st.find(x)!=st.end()){
                        f = 1;
                        break;
                    }else{
                        st.insert(x);
                    }
                }
            }
            cout<<(f?"YES\n":"NO\n");
        }
        
    }
    

    return 0;
}