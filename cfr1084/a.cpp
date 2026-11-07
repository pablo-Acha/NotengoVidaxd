#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = *max_element(arr.begin(),arr.end());            
        ll cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == mx){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    
    return 0;
}