#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    int cnt = 0;
    for (int i = 0; i < 10000; i++)
    {
        if(a>b){
            break;
        }
        cnt++;
        a = a*3;
        b = b*2;
    }
    cout<<cnt<<"\n";
    return 0;
}