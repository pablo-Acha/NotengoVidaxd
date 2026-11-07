#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    long long res = 0;
    for (int i = 0; i < n; i++)
    {
        long long val = 0;
        for (int j = 0,a; j < 3; j++)
        {
            cin>>a;
            val+=a;
        }
        res += (val>1);
    }
    cout<<res<<"\n";
    return 0;
}