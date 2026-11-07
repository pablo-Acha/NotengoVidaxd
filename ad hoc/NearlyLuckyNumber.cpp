#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n = s.size();
    long long val = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '4' || s[i]== '7'){
            val++;
        }
    }
    bool flag = 1;
    if(val == 0){
        cout<<"NO"<<"\n";

        return 0;
    }
    while(val){
        if(val%10 == 7 || val%10 == 4){val = val/10;continue;}
        flag = 0;
        break;
    }
    if(flag){
        cout<<"YES"<<"\n";
    }else{
        cout<<"NO"<<"\n";
    }


    return 0;
}