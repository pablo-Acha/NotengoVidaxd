#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    set<char> a;
    for (int i = 0; i < s.size(); i++)
    {
        s[i]= towlower(s[i]);
        a.insert(s[i]);
    }
    if(a.size()!=26){
        cout<<"NO"<<"\n";
    }else{
        cout<<"YES"<<"\n";
    }
    
    return 0;
}