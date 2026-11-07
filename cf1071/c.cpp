#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        if(arr[1]-arr[0] < arr[0]){
            cout<<arr[0]<<endl;
        }else{
            cout<<arr[1]-arr[0]<<endl;
        }
    }
    return 0;
}