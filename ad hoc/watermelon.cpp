#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    if(n>3 && !(n&1)){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }
    return 0;
}