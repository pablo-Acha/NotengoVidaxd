#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string arr;cin>>arr;
        long long dis = 0;
        for (int i = 0; i < n; i++)
        {
            if(arr[i] == '1'){
                long long j = (i+1)%n,val = 0;
                while(arr[(j%n)]!='1'){
                    val++;j++;
                }
                dis = max(val,dis);
            }
        }
        cout<<dis<<endl;
    }
    return 0;
}