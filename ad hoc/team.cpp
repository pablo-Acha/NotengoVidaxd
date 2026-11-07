#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a,b,c;cin>>a>>b>>c;
        int x = a+b+c;
        if(x>1)res++;
    }
    cout<<res<<endl;
    return 0;
}