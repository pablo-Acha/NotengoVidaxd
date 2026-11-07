#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    set<char> a;
    for (auto x:s)
    {
        a.insert(x);
    }
    
    if(a.size()&1){
        cout<<"IGNORE HIM!"<<"\n";
    }else{
        cout<<"CHAT WITH HER!"<<"\n";
    }
    return 0;
}