#include<bits/stdc++.h>
using namespace std;
int pot(int n,int a){
    int res = 1;
    for (int i = 0; i < a; i++)
    {
        res = res*n;
    }
    return res;    
}
int main(){
    int t;cin>>t;
    while (t--)
    {
        long long n;cin>>n;
        int i = 0;
        vector<int> arr;
        while(n){
            arr.push_back(n%10);
            n/=10;
        }
        int res = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if(arr[i]!=0){
                res++;
            }
        }
        cout<<res<<"\n";
        for (int i = arr.size()- 1; i >= 0; i--)
        {
            if(arr[i]!=0){
                cout<<(arr[i] * pot(10,i))<<" ";
            }
        }
        cout<<"\n";
           
    }
    
    return 0;
}