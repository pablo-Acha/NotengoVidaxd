#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;

    int res = 0;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        res  = res|a;
    }
    if(res){
        cout<<"HARD"<<"\n";
    }else{
        cout<<"EASY"<<"\n";
    }
    return 0;
}