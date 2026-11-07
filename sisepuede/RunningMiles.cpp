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
        ll l = 0, r = n-1;
        vll brr(n),crr(n);
        set<ll> st;
        for (int i = 0, j = n-1; i < n; i++,j--)
        {   
            brr[i] = arr[i]-j;
            crr[j] = arr[j]-j;
            st.insert(crr[j]);
        }
        for (int i = 0; i < n; i++)
        {
            
        }
        
    }

    return 0;
}