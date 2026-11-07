#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    char x;cin>>x;
    map<char,vector<int>> mp;
    mp['A'] = {11,11}; 
    mp['K'] = {4,4}; 
    mp['Q'] = {3,3}; 
    mp['J'] = {20,2}; 
    mp['T'] = {10,10}; 
    mp['9'] = {14,0}; 
    mp['8'] = {0,0}; 
    mp['7'] = {0,0};
    int res = 0;
    for (int i = 0; i < n*4; i++)
    {
        string s;cin>>s;
        if(s[1] == x){
            res+= mp[s[0]][0];
        }else{
            res+= mp[s[0]][1];
        }
    }
    cout<<res<<"\n";
    return 0;
}