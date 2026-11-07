#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    double x = 0,a;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        x+=a;
    }
    double  res = x/(n);
    cout<<res<<"\n";
    return 0;
}