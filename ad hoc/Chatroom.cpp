#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    string aux = "hello";
    int j = 0;
    for (int i = 0; i < s.size()&& j <aux.size(); i++)
    {
        if(s[i] == aux[j])j++;
    }
    if(j == aux.size())cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
    return 0;
}