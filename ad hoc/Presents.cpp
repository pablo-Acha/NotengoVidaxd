#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    vector<int>res(n);
    for (int i = 0; i < n; i++)
    {
        res[arr[i]-1]  = i+1;
    }
    for(auto a:res){
        cout<<a<<" ";
    }
    cout<<"\n";
    return 0;
}