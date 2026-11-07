#include<bits/stdc++.h>
using namespace std;
int main(){
    string s,a = "";cin>>s;
    set<char> st = {'A', 'O', 'Y', 'E', 'U', 'I','a', 'o', 'y', 'e', 'u', 'i'};

    for (int i = 0; i < s.size(); i++)
    {
        if(st.find(s[i]) == st.end()){
            char x = tolower(s[i]);
            a = a + x;
        } 
    }

    for (int i = 0; i <a.size(); i++)
    {
        cout<<"."<<a[i];
    }
    cout<<"\n";
    return 0;
}