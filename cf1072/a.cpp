#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        if(x == 2){cout<<2<<"\n";continue;}
        if(x == 3){cout<<3<<"\n";continue;}

        cout<<x%2<<"\n";
    }    
    return 0;
}