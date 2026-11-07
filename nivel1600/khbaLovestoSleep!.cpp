#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool fun(vll &arr, ll k, ll lim, ll mid){
    ll ini = 0;
    ll n  = arr.size();
    for (int i = 0; i < n; i++)
    {
        ll fn = arr[i]-mid;
        if(ini<= fn){
            k-= (fn-ini+1);
        }
        ini = arr[i]+mid;
    }
    if(ini<= lim){
        k-= (lim-ini+1);
    }
    return k<=0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n,k,x;cin>>n>>k>>x;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(all(arr));
        ll l = 1,r = x,mid;
        while(l<=r){
            mid = (l+r)/2;
            if(fun(arr,k,x,mid)){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        ll ini = 0;
        vll res;
        bool f = 1;
        // cout<<r<<"\n";
        if(r == 0){
            for (int i = 0; i < k; i++)
            {
                cout<<i<<" ";   
            }
            cout<<"\n";
            continue;
        }
        for (int i = 0; i < n &&f; i++)
        {
            ll fn = arr[i]-r;
            if(ini<= fn){
                for (int i = ini; i <= fn && f; i++)
                {
                    res.push_back(i);    
                    if(res.size() == k){f = 0;break;}
                }
            }
            ini = arr[i]+r;
        }

        if(ini<= x){
            for (int i = ini; i <= x && f; i++)
            {
                res.push_back(i);    
                if(res.size() == k){f = 0;break;}
            }
        }
        for(auto x:res)cout<<x<<" ";
        cout<<"\n";
    }

    return 0;
}