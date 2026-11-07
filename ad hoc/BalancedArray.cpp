#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if((n/2) &1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            int x = n/2;
            int sum = 0;
            for (int i = 0,j = 2; i < x; i++,j+=2)
            {
                cout<<j<<" ";
                sum+=j;
            }
            for (int i = 0,j = 1; i < x-1; i++,j+=2)
            {
                cout<<j<<" ";   
                sum-=j;
            }          
            cout<<sum<<"\n";  
        }
    }

    return 0;
}