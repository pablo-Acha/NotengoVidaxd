#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l;cin>>n>>l;
    if(0>=l && 0<=l+n-1){
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res+= l+i;
        }
        cout<<res<<"\n";
    }else{
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res+= l+i;
        }
        if(res<0){
            cout<<res-(l+n-1)<<"\n";
        }else{
            cout<<res-(l)<<"\n";
        }
    }
    return 0;
}