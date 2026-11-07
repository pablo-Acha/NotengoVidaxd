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
        ll n,m;cin>>n>>m;
        deque<ll> arr(m);for(auto &a:arr)cin>>a;
        sort(all(arr));
        for (int i = 0; i < m; i++)
        {
            if(arr[i]>n-1)arr[i] = n-1;
        }
        
        vll act(m);
        ll j = 0;
        deque<ll> brr= arr;
        vll conta(m);
        for (int i = 0; i < m-1; i++)
        {
            // cout<<i<<" ";
            ll aux = n-arr[0];
            arr.pop_front();
            ll ind = lower_bound(arr.begin(),arr.end(),aux)-arr.begin();
            j++;
            if(ind+j<m){
                // cout<<arr[ind]<<"\n";
                act[ind+j] += arr[ind]-aux+1; 
                conta[ind+j]++;
            }
        }

        ll cant = 0;
        ll acc = 0;
        ll res = 0;
        for (int i = 1; i < m; i++)
        {
            acc = acc + (cant*(brr[i]-brr[i-1]))+act[i];
            res += acc;
            if(act[i]>0)cant+= conta[i];
        }
        // for (int i = 0; i < m; i++)
        // {
        //     cout<<brr[i]<<" ";
        // }
        // cout<<"\n";
        // for (int i = 0; i < m; i++)
        // {
        //     cout<<act[i]<<" ";
        // }
        // cout<<"\n";
        cout<<res*2<<"\n";
        // cout<<"----\n";
        // for (int i = 0; i < m; i++)
        // {
        //     cout<<act[i]<<" ";
        // }
        // cout<<"\n";
        
        
    }

    return 0;
}