#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        long long n;cin>>n;
        cout<<((n/2) + (n&1))<<"\n";
    }
    return 0;
}