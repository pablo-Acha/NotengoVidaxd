#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<long long> arr(n);
        vector<long long> brr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin>>brr[i];
        }
        sort(arr.begin(),arr.end());
        sort(brr.begin(),brr.end(),greater<int>());
        for (int i = 0; i < k; i++)
        {
            if(arr[i]<brr[i]){
                swap(arr[i],brr[i]);
            }else{
                break;
            }
        }
        int res = accumulate(arr.begin(), arr.end(), 0);
        cout<<res<<"\n";
        
    }
    return 0;
}