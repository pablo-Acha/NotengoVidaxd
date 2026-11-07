#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    vll ini = arr;
    vll fn = arr;
    sort(all(ini));
    sort(all(fn),greater<ll>());
    vll ne = arr;
    bool hasNext = next_permutation(all(ne));
    vll pre = arr;
    bool hasPrev = prev_permutation(all(pre));
    if(hasPrev){
        for (int i = 0; i < n; i++)
        {
            cout<<pre[i];
            if(i<n-1)cout<<" ";            
        }        
        cout<<endl;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i];
        if(i<n-1)cout<<" ";
    }   
    cout<<endl;
    if(hasNext){
        for (int i = 0; i < n; i++)
        {
            cout<<ne[i];
            if(i<n-1)cout<<" ";
        }   
        cout<<endl;
    }

    return 0;
}