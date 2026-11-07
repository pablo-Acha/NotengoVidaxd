#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        set<ll> st;
        vll arr(n);for(auto &a:arr){cin>>a;st.insert(a);}
        if(st.size()!=n){
            cout<<-1<<"\n";
        }else{
            sort(arr.begin(),arr.end(),greater<ll>());
            for (int i = 0; i < n; i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;   
}