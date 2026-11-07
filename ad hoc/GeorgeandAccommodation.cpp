#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        res+= (b-2>=a);
    }
    cout<<res<<"\n";
    return 0;
}