#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;cin>>n;
    if(n&1){
        if((n/2)&1){
                cout<<"YES"<<"\n";
                cout<<n/2<<"\n";
                int j = 1;
                for (int i = 0; i < (n/2) - 1; i+=2,j++)
                {
                    cout<<j<<" "<<n-j<<" ";
                }
                cout<<n<<"\n";
                cout<<(n/2) + 1<<"\n";
                for (int i = 0; i < (n/2) + 1; i+=2,j++)
                {
                    cout<<j<<" "<<n-j<<" ";
                }
                cout<<'\n';
            }else{
                cout<<"NO"<<"\n";
            }
    }else{
        if((n/2)%2 == 0){
            cout<<"YES"<<"\n";
            cout<<(n/2)<<"\n";
            int j= 1;
            for (int i = 0; i < (n/2); i+=2,j++)
            {
                cout<<j<<" "<<(n+1)-j<<" ";
            }
            cout<<"\n"<<(n/2)<<"\n";
            for (int i = 0; i < (n/2); i+=2,j++)
            {
                cout<<j<<" "<<(n+1)-j<<" ";
            }
        }else{       
            cout<<"NO"<<"\n";
        }
    }
    
    return 0;
}