#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int l,a,b;cin>>l>>a>>b;
        if(b>=l){
            if(b%l ==0){
                cout<<a<<endl;
            }else{
                cout<<l-1<<endl;
            }
        }else if(b<l){
            if(l%b ==0){
                cout<<l-b+a<<endl;
            }else{
                cout<<l-1<<endl;
            }
        }
    }
    return 0;
}