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
        vector<vll> arr(n,vll(n));
        for(auto &v:arr)for(auto &x:v)cin>>x;
        for (int i = 0; i < n; i++)
        {
            reverse(all(arr[i]));
            ll j = 0;
            while(j<n && arr[i][j]==1)j++;
            while(j<n){ arr[i][j] = 0;j++;}
        }
        sort(all(arr));
        ll aux = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i][0] == 0)aux++;
            else break;
        }
        
        ll res = 1;
        bool f= 1;
        // for(auto v:arr){for(auto x:v)cout<<x<<" ";cout<<"\n";}
        // cout<<aux<<"\n";
        for (int i = 0,j = 1; i < n; i++)
        {
            ll cnt = 0;
            while(cnt<n && arr[i][cnt] == 1)cnt++;
            // if(cnt<j)break;
            if(cnt>=j){
                res++;
                j++;
            }else f = 0;
        }
        cout<<res-f<<"\n";
    }

    return 0;
}