#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;cin>>n;
    long long res = 0;
    for (int i = 0,a; i < n-1; i++)
    {
        cin>>a;
        res+= a;
    }
    cout<<(((n*(n+1))/2)-res)<<"\n";

    return 0;
}