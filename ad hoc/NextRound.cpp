#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;cin>>n>>k;
    int res  = 0;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int umbral = arr[k-1];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>0 && arr[i]>=umbral){
            res++;
        }else{
            break;
        }
    }
    cout<<res<<"\n";
    
    return 0;
}