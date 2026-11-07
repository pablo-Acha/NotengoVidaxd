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
        ll n,m,k;cin>>n>>m>>k;
        vll arr(m);for(auto &a:arr)cin>>a;
        ll mx = *max_element(all(arr));
        if(mx>(n/k)+((n%k)>0LL) || k>m) {
            cout<<"NO\n";
        }else{
            ll cnt = 0;
            for (int i = 0; i < m; i++){
                if((n%k>0) && arr[i] == (n/k)+1){
                    cnt++;
                }   
            }
            // cout<<n/k<<"\n";
            // cout<<cnt<<" "<<(n/k)+((n%k)>0LL)<<"\n";
            if(cnt>(n%k)){
                cout<<"NO\n";
            }else{
                cout<<"YES\n";
            }
        }
        
    }    

    return 0;
}