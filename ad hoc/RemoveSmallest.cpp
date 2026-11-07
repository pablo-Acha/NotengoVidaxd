#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<long long> arr(n);
        for(auto &a:arr)cin>>a;
        sort(arr.begin(),arr.end());
        bool f = 1;
        for (int i = 0; i < n-1; i++)
        {
            if((arr[i+1]-arr[i])>1){
                f = 0;

                break;
            }
            // cout<<(arr[i+1]-arr[i])<<" ";
        }
        cout<<(f?"YES":"NO")<<"\n";
    }
    return 0;
}