#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    string s;cin>>s;
    int q;cin>>q;
    int n = s.size();
    s= '='+s;
    vll arr(n+1);
    for (int i = 1; i < n; i++)
    {
        if(s[i] == s[i+1]){
            arr[i]++;
        }
        arr[i]+=arr[i-1];
    }
    for (int i = 0; i < q; i++)
    {
        ll a,b;cin>>a>>b;
        ll res = arr[b-1]-arr[a-1];
        cout<<res<<"\n";
    }
       
    return 0;
}