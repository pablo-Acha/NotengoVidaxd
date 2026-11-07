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
        vector<ll> fr(n+1);
        ll mx = 0;
        ll sum = accumulate(all(arr),0LL);
        for (int i = 0; i < n; i++)
        {
            fr[arr[i]]++;
            if(fr[arr[i]]>1)mx = max(arr[i],mx);
            arr[i] = mx;
        }
        sum+= accumulate(all(arr),0LL);
        fill(all(fr),0);
        mx = 0;
        for (int i = 0; i < n; i++)
        {
            fr[arr[i]]++;
            if(fr[arr[i]]>1)mx = max(arr[i],mx);
            arr[i] = mx;
        }
        ll aux = 0;
        for (int i = n - 1; i >= 1; )
        {
            if(arr[i] == 0)break;
            ll v = arr[i];
            ll cnt = 0;
            while(arr[i] == v)
            {
                i--;
                cnt++;
            }
            sum += (aux*v*cnt) + ((cnt*(cnt+1))/2)*v;
            aux += cnt;

        }
        cout<<sum<<"\n";
        // for(auto x:arr)cout<<x<<" ";
        // cout<<"\n";
    }
    

  return 0;
}