#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        long long y,x;cin>>y>>x;
        if(y == 1 && x == 1){cout<<1<<"\n";continue;}
        if(y>=x){
            if(y&1){
                long long c = (y-1)*(y-1);
                cout<<c+x<<"\n";
            }else{
                long long c = (y)*(y);
                cout<<c-x+1<<"\n";
            }
        }else{
            if(x&1){
                long long c = (x)*(x);
                cout<<c-y+1<<"\n";
            }else{
                long long c = (x-1)*(x-1);
                cout<<c+y<<"\n";
            }
            
        }
    }
    
    return 0;
}