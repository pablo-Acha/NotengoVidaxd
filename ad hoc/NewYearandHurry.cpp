#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,k;cin>>a>>k;
    int t = 240-k;
    int res = 0;
    for (int i = 1; i <= a; i++)
    {
        if(t<5*i)break;
        t = t-(5*i);
        res++;
    }
    cout<<res<<"\n";
    return 0;
}