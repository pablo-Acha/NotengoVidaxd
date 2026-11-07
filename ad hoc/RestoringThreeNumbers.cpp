#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> arr(4);
    for (int i = 0; i < 4; i++)
    {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    cout<< arr[0]+arr[1]-arr[3]<<" ";
    cout<<arr[0]+arr[2]-arr[3]<<" ";
    cout<<arr[1]+arr[2]-arr[3]<<"\n";
    
    
    return 0;
}