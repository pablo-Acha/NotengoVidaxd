#include<bits/stdc++.h>
using namespace std;
int f(int n,int m){
    int res = ((n/2)*m)  + (n&1?(m/2)+(m&1):0);
    return res;
}
int main(){
    int t;cin>>t;
    while(t--){
        int x,y;cin>>x>>y;

        cout<<min(f(x,y),f(y,x))<<"\n";
    }
    return 0;
}