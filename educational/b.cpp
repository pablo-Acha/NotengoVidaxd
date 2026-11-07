#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while (t--)
    {
        int n;cin>>n;
        vector<long long> arr(n);
        vector<long long> ind(n);
        for(auto &a:arr)cin>>a;
        ind[0] = -1;
        long long imx = 0;
        long long mx = arr[0];
        int res  = 1;
        for (int i = 1; i < n; i++)
        {
            if(arr[i]>=mx){
                mx = arr[i];
                res++;
            }else{
                ind[i] = imx;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}