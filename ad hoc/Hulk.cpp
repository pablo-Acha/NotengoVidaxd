#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    for (int i = n,j  = 1; i >0; i--,j++)
    {
        if(j&1){
            cout<<"I hate ";
        }else{
            cout<<"I love ";
        }
        if(i == 1){
            cout<<"it"<<"\n";
        }else{
            cout<<"that ";
        }
    }
    
    return  0;
}