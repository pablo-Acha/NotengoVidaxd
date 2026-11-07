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
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);
        ll f = 1;
        for (int i = 0; i < n;)
        {
            ll aux = arr[i];
            ll cnt = 0;
            while(i<n && aux == arr[i]){
                brr[i] = aux;
                i++;
                cnt++;
            }
            if(cnt== 1)brr[i-1] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            if(brr[i]!=0 && brr[i-1]!=0){
                if(brr[i]!=brr[i-1]){
                    swap(arr[i],arr[i-1]);
                    f = 0;
                    break;
                }
            }
        }
                
        if(f)for (int i = 0; i < n;)
        {
            ll aux = arr[i];
            ll ini = i;
            while(i<n && aux == arr[i]){
                i++;
            }
            ll fn = i-1;
            if(fn-ini>0){
                if(f && ini-1>=0){
                    swap(arr[ini],arr[ini-1]);
                    if(ini-2>=0 && arr[ini-2] == arr[ini-1] ){
                        swap(arr[ini],arr[ini-1]);
                    }else{
                        f = 0;
                        break;
                    }
                }
                if(f && fn+1<n){
                    swap(arr[fn],arr[fn+1]);
                    if(fn+2<n && arr[fn+2] == arr[fn+1] ){
                        swap(arr[fn],arr[fn+1]);
                    }else{
                        f = 0;
                        break;
                    }
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < n; )
        {
            ll aux = arr[i];
            while(i<n &&aux == arr[i]){
                i++;
            }
            res++;
        }
        // for(auto x:arr)cout<<x<<" ";
        // cout<<"\n";
        // cout<<f<<"\n";
        cout<<res<<"\n";
        
    }

    return 0;
}