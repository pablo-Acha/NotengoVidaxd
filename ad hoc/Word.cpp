#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int lo = 0;
    int up = 0;
    for (int i = 0; i < s.size(); i++)
    {
        // cout<<int(s[i])<<" ";
        if(s[i]-'a'>=0 && s[i]-'a'<=26){
            lo++;
        }else{
            up++;
        }
    }


    // cout<<up<<" "<<lo<<"\n";
    if(up>lo){
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = toupper(s[i]);
        }
        cout<<s<<"\n";
    }else{
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        cout<<s<<"\n";
    }
    return 0;
}