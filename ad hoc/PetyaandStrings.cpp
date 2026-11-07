#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    string c;cin>>c;
    string a = "",b = "";
    for (int i = 0; i < s.size(); i++)
    {
        a.push_back(tolower(s[i]));
        b.push_back(tolower(c[i]));
    }
    if(a==b){
        cout<<0;
    }else if(a>b){
        cout<<1;
    }else{
        cout<<-1;
    }
    cout<<"\n";
    return 0;
}