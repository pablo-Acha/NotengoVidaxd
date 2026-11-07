#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    int mn = min(a,b);
    cout<<mn<<" ";
    int mx = max(a,b);
    cout<<(mx-mn)/2<<"\n";
    return 0;
}