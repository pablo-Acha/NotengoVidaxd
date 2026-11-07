#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll resta(char a,char b){
    if(a<b){
        return a+10 - b;
    }
    return a-b;
}
int main(){
    ll n, m;cin>>n>>m;
    string s,t;cin>>s>>t;
    ll res = 1e10;
    for (int i = 0; i <= n-m; i++)
    {
        ll cnt = 0;
        for (int j = 0; j < m; j++)
        {
            cnt += resta(s[i+j],t[j]);
        }
        res = min(res,cnt);
    }
    cout<<res<<endl;
    return 0;
}