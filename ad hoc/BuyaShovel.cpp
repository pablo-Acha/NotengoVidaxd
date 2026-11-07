#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    for (int i = 1; i < 20; i++)
    {
        if((a*i)%10 == b || (a*i)%10 == 0){
            cout<<i<<"\n";
            break;
        }
    }
    
    return 0;
}