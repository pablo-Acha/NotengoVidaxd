#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        vll brr(n);
        for (int i = 0; i < n; i++)
        {
            brr[i] = arr[i] -((arr[i]/2)+1);
            brr[i] = max(brr[i],0LL);
        }
        multiset<ll> st;
        multiset<ll> st2;
        ll mx = 0;
        // for(auto a:brr)cout<<a<<" ";
        // cout<<"\n";
        
        for (int i = 0; i < n; i++)
        {
            if(mx<=brr[i]){
                mx++;
            }else if(mx == arr[i]){
                mx++;
                continue;
            }else if(st2.find(mx)!= st2.end()){
                st2.erase(st2.find(mx));
                mx++;
                st2.insert(arr[i]);
                continue;
            }else if(st.find(mx)!= st.end()){
                st.erase(st.find(mx));
                mx++;
            }else {
                st2.insert(arr[i]);
                continue;
            }
            st.insert(arr[i]);
        }
        while(st2.find(mx)!= st2.end()){
            mx++;
        }
        cout<<mx<<"\n";
        
    }

    return 0;
}