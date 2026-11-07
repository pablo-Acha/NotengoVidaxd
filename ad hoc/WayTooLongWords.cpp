#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){ 
        string s;cin>>s;
        int num = s.size()-2;
        if(s.size()<=10){
            cout<<s<<"\n";
        }else{
            cout<<s[0]<<num<<s[s.size()-1]<<"\n";
        }   
    }
    
    return 0;

}