#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>
ll f(char x){
    return x-'0';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        string s;cin>>s;
        int n = s.size();
        ll mn = 100;
        map<ll,ll> mp;
        for (int i = n - 1; i >= 0; i--)
        {
            if(f(s[i])>mn){
                ll aux = min(9LL,f(s[i])+1LL);
                mp[aux]++;
            }else{
                mn= min(mn,f(s[i]));
                mp[f(s[i])]++;
            }
        }
        vll arr;
        for(auto [a,b]:mp){
            for (int i = 0; i < b; i++)
            {
                arr.push_back(a);
            }
            
        }
        for (int i = 0; i < n; i++)
        {
            cout<<arr[i];
        }
        cout<<"\n";
    }
    
    return 0;
}