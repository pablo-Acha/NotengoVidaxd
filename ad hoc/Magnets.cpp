#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s = "";
    string a ="";
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        s.push_back(a[0]);
        s.push_back(a[1]);
    }
    int res = 0;
    for (int i = 1; i < s.size()-1; i+=2)
    {
        if(s[i] ==s[i+1]){
            res++;
        }
    }
    cout<<res+1<<"\n";
    return 0;
}