#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ll t;cin>>t;
    while(t--){
        double n,k;cin>>n>>k;
        vector<double> arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end(),greater<ll>());
        double m = 0;
        double acc = 0;
        int i = 0;
        while(i<n && (acc+arr[i])/(m+1) >=k){
            acc+=arr[i];
            i++;
            m++;
        }
        cout<<m<<"\n";
    }
    return 0;
}