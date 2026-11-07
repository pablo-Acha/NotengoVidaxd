#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,h;cin>>n>>h;
    vector<int> arr(n);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
        res+= arr[i]>h?2:1;
    }
    cout<<res<<"\n";
    
    return 0;
}