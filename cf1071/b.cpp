#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;


int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr(n);
        brr[0] = abs(arr[0]-arr[1]);
        brr[n-1] = abs(arr[n-1]-arr[n-2]);
        for (int i = 1; i < n-1; i++)
        {
            brr[i] = abs(abs(arr[i-1]-arr[i+1])-abs(abs(arr[i-1]-arr[i])+abs(arr[i]-arr[i+1])));    
        }
        int inmax = -1;
        ll mx = -1;
        for (int i = 0; i < n; i++)
        {
            if(mx<brr[i]){
                inmax = i;
                mx = brr[i];
            }
        }
        // for(auto a:brr)cout<<a<<" ";
        // cout<<endl;
        ll ant = 0;
        ll res = 0;
        // cout<<inmax<<endl<<mx<<endl;
        vll crr;
        for (int i = 0; i < n; i++)
        {
            if(i == inmax)continue;
            crr.push_back(arr[i]);
        }
        for (int i = 1; i < (int)crr.size(); i++)
        {
            res+= abs(crr[i]-crr[i-1]);
        }
        cout<<res<<endl;
           
    }
    return 0;
}