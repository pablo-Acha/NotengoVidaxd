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
        ll n,k;cin>>n>>k;
        stack<ll> st;
        stack<ll> st2;
        vll arr(n);
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
            arr[i] -=k;
            // st.push(a-k);
        }
        ll res = 0;
        sort(all(arr),greater<ll>());
        for (int i = 0; i < n; i++)
        {
            if(arr[i]>=0){
                res+= arr[i];
            }else if(cnt< n/2 + (n&1)){
                res+= arr[i];    
            }else{
                break;
            }
            cnt++;
        }
        cout<<res<<"\n";
    }

    return 0;
}