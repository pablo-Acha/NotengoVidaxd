#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    int mn = min(n,m);
    if(mn&1){
        cout<<"Akshat"<<"\n";
    }else{
        cout<<"Malvika"<<"\n";
    }
    return 0;
}