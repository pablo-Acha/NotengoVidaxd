#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    if(n&1){
        cout<<(-1*((n+1)/2))<<"\n";
    }else{
        cout<<n/2<<"\n";
    }
    return 0;
}