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
        ll n,c;cin>>n>>c;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll act(n);
        for (int i = n - 2; i >= 0; i--)
        {
            act[i] = max(act[i+1],arr[i+1]);
        }
        vll res(n,-1);
        arr[0] +=c;                 
        ll mx = *max_element(all(arr));
        for (int i = 0; i < n; i++)
        {
            if(mx == arr[i]){
                res[i] = 0;
                break;
            }
        }
        arr[0]-=c;
        ll sum= accumulate(all(arr),0LL);
        for (int i = 0,j = n; i < n; i++,j--)
        {
            if(res[i] ==-1){
                if(arr[i]+c>=act[i]){
                    res[i] = i;
                }else{
                    res[i]= i+1;
                }
            }
            c+= arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout<<res[i]<<" ";
        }
        cout<<"\n";
        
        
    }

    return 0;
}