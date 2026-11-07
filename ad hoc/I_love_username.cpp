#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int a;cin>>a;
    int mn = a;
    int mx = a;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        cin>>a;
        if(a>mx){
            mx = a;
            res++;
        }
        if(a<mn){
            mn = a;
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}