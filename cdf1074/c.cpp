#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        set<ll> st;
        for (int i = 0,a; i < n; i++)
        {
            cin>>a;
            st.insert(a);
        }
        
        vll arr;
        for(auto a:st)arr.push_back(a);
        
        sort(arr.begin(),arr.end());
        // for(auto x:arr)cout<<x<<" ";
        // cout<<"\n"<<"\n";
        ll val = 1;
        ll mx = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            // cout<<arr[i]<<" ";
            if(arr[i]-1 == arr[i-1]){
                val++;
            }else {
                mx = max(val,mx);
                val = 1;
            }
        }
        cout<<(max(mx,val))<<"\n";
        
    }
    return 0;
}