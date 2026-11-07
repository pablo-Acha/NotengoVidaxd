#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int iz = 0,der = n;
    int mx = -1,mn = 1e9+1;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>mx){
            mx = arr[i];
            iz = i;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if(arr[i]<mn){
            mn = arr[i];
            der = i;
        }
    }
    int res = iz+ (n-1 -der);
    if(der<iz){
        res--;
    }
    cout<<res<<"\n";

    return 0;
}