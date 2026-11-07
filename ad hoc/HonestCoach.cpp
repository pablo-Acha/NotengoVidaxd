#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        int mn = 1e9;
        for (int i = 1; i < n; i++)
        {
            mn = min(mn,arr[i]-arr[i-1]);
        }
        cout<<mn<<"\n";
    }
    return 0;
}