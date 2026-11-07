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

    ll n;cin>>n;
    vll arr(n);for(auto &a:arr)cin>>a;
    ll mn = 1e18;
    sort(all(arr));
    for (int i = 0; i < (1<<n); i++)
    {
        ll sum = 0;
        ll mx = 0;
        for (int j = 0; j < n; j++)
        {
            if((i>>j)&1){
                sum+=arr[j];
            }else{
                sum-=arr[j];
            }
            mx = max(mx,abs(sum));                
        }
        mn = min(mx,mn);
    }
    cout<<mn<<"\n";

    return 0;
}