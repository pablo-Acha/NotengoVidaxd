#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int exi = 0;
    int res = 0;
    for (int i = 0,a; i < n; i++)
    {
        cin>>a;
        if(a<0){
            exi--;
            res+= exi<0;
            exi = max(0,exi);
        }else{
            exi+=a;
        }
    }
    cout<<res<<"\n";
    return 0;
}