#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    long long res = 0;
    for (int i = 1; i < n; i++)
    {
        res+= max(arr[i-1]-arr[i],0LL);
        arr[i] += max(arr[i-1]-arr[i],0LL);
    }
    cout<<res<<"\n";
    return 0;
}