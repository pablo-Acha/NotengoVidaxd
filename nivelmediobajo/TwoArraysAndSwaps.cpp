#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vll arr(n),brr(n);
        for(auto &a:arr)cin>>a;
        for(auto &b:brr)cin>>b;
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end(),greater<ll>());
        for (int i = 0; i < k; i++)
        {
            if(arr[i]<brr[i]){
                swap(arr[i],brr[i]);
            }else{
                break;
            }
        }
        ll res = accumulate(arr.begin(),arr.end(),0);
        cout<<res<<"\n";
    }
    
    return 0;
}