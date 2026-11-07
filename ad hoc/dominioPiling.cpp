#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int mx = max(n,m);
    int mn = min(n,m);
    if(n == 1 && m==1){
        cout<<0<<"\n";
    }else if(n == 1 || m == 1){
        cout<<mx/2<<"\n";
    }else{
        int res1 = (n* (m/2))  + (m&1?n/2:0);
        int res2 = (m* (n/2))  + (n&1?m/2:0);
        int resf = max(res1,res2);
        cout<<resf<<"\n";
    }
    return 0;
}