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
    ll res = (n*(n-1))/2;
    set<ll> st;
    vector<pll> brr;
    for (int i = n; i >=1; i--)
    {
        for (int j = i-1; j >=1; j--)
        {
            brr.push_back({i,j});
        }
    }
    
    for (ll i = 0; i < n; i++)
    {
        st.insert(i+1);
    }
    
    for (int i = n - 1; i >= 0; i--)
    {
        auto x = st.lower_bound(arr[i]);
        for (auto it = x; ; it =prev(it))
        {
            if(x != it){
                brr.push_back({*it,*x});
                res++;
            }
            if(it == st.begin())break;
        }
        st.erase(x);
    }
    cout<<res<<"\n";
    for(auto [x,y]:brr){
        cout<<x<<" "<<y<<"\n"; 
    }
      
    

    return 0;
}