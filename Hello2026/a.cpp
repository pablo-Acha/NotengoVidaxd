#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;

int main(){
    int t;cin>>t;
    
    while(t--){
        int n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        if(!arr[0] && !arr[n-1]){
            cout<<"Bob"<<endl;
        }else{
            cout<<"Alice"<<endl;
        }
    }
    return 0;
}