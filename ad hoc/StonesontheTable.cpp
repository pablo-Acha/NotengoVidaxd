#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    char l = s[0];
    int res = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] == l){
            res++;
        }
        l = s[i];
    }
    cout<<res<<"\n";
    return 0;
}