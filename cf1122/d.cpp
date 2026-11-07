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
        vector<pll> arr(n);
        for (int i = 0; i < n; i++)
        {
            auto &[val,ind] = arr[i];
            cin>>val;
            ind = i;            
        }
        sort(all(arr));
        for(int i = 0; i < n; i++)
        {
            arr[i].first += arr[i].second-i;
        }
        ll res = 0;
        ll cnt = 0;
        ll tope = arr[0].first;
        for(auto [x,v]:arr){
            cout<<x<<" ";
        }
        cout<<"\n";

        for (int i = 1; i < n; i++)
        {
            if(tope == arr[i].first){
                cnt++;
                res = max(cnt,res);
            }else if(tope<arr[i].first){
                ll dif = arr[i].first-arr[i-1].first;
                if(dif>=cnt+1){
                    tope++;
                    cnt++;
                }
            }
        }
        cout<<res<<"\n";
        
    }


    return 0;
}