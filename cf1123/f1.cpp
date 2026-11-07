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
        ll n,q;cin>>n>>q;
        vll arr(n);for(auto &x:arr)cin>>x;
        ll tam = 61;
        vll ca(tam);
        ll tm = *max_element(arr.begin(),arr.end());
        ll tn = *min_element(arr.begin(),arr.end());
        ca[0] = tm-tn;
        for (int h = 1; h <tam; h++)
        {
            vll bruta;
            for (int i = 0; i < n; i++)
            {
                for (int j = i+1; j < n; j++)
                {
                    bruta.push_back(arr[i]^arr[j]);
                }                
            }
            sort(all(bruta));
            // if(h == 1){for (int i = 0; i < n; i++)
            // {
            //     cout<<bruta[i]<<" ";
            // } cout<<"\n";}
            
            ll mx  = *max_element(bruta.begin(),bruta.begin()+n);
            ll mn  = *min_element(bruta.begin(),bruta.begin()+n);
            for (int i = 0; i < n; i++)
            {
                arr[i] = bruta[i];
            }
            
            ca[h] = mx-mn;
        }
        
        for (int i = 0; i < q; i++)
        {
            ll a;cin>>a;
            if(a>=tam){
                cout<<ca[60]<<"\n";
            }else{
                cout<<ca[a]<<"\n";
            }
        }
        
    }

    return 0;
}