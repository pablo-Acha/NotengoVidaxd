#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<string> srr(n);for(auto &a:srr)cin>>a;
        string s = srr[0];
        string mn = srr[0];
        for (int i = 1; i < n; i++)
        {
            string s1 = srr[i]+s,s2 = s+srr[i];
            if(s1<s2){
                s = s1;
            }else{
                s = s2;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}