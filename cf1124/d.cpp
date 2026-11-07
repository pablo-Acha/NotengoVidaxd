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
    set<ll> si= {0, 3 ,5, 6,9, 10, 12 ,15 };
    while(t--){
        ll n,q;cin>>n>>q;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll res = 0;
        
        for (int i = 0; i < n; i++)
        {
            if(si.find(arr[i])!=si.end()){
                res++;
            }
        }
        cout<<res<<" ";
        for (int i = 0; i < q; i++)
        {
            ll ind,v;cin>>ind>>v;
            ind--;
            if(si.find(arr[ind]) != si.end()){
                res--;
            }
            arr[ind] = v;
            if(si.find(arr[ind]) != si.end()){
                res++;
            }
            cout<<res<<" ";
        }
        cout<<"\n";
    }
    

    return 0;
}