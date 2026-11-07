#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long a,b,x;cin>>a>>b>>x;
        long long r = x/a;
        if((r*a)+b<=x){
            cout<<(r*a)+b<<"\n";
        }else{
            cout<<((r-1)*a)+b<<"\n";
        }
    }
    return 0;
}