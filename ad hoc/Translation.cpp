#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,c;cin>>s>>c;
    bool f= 0;
    if(s.size()!=c.size()){
        cout<<"NO"<<"\n";
        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == c[s.size()-i-1])continue;
        f = 1;
        break;
    }
    cout<<(f?"NO":"YES")<<"\n";
    return 0;
}