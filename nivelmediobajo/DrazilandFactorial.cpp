#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    map<char,ll> mp;
    sort(s.begin(),s.end());
    for (int i = 0; i < n; i++)
    {
        if(s[i] == '0' || s[i] == '1')continue;
        if(s[i] == '4'){
            mp['2']+=2;
            mp['3']++;
        }else if(s[i] == '6'){
            mp['3']++;
            mp['5']++;
        }else if(s[i] == '8'){
            mp['7']++;
            mp['2']+=3;
        }else if(s[i] == '9'){
            mp['7']++;
            mp['2']++;
            mp['3']++;
            mp['3']++;
            
        }else{
            mp[s[i]]++;
        }
    }
        string res = "";
        for(auto &[a,b]:mp){
            for (int i = 0; i < b; i++)
            {      
                res.push_back(a);
            }
        }
        reverse(res.begin(),res.end());
        cout<<res<<"\n";       
    return 0;
}