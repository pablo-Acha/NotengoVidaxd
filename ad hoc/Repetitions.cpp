#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int res  = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char x = s[i];
        while(i<s.size() && s[i] == x){
            cnt++;
            i++;
        }        
        res = max(cnt,res);
        cnt = 0;
        i--;
    }
    cout<<max(res,cnt)<<"\n";
    return 0;
}