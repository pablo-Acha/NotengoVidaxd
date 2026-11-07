#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    string s;cin>>s;
    string x = "";
    for (int i = 0; i < s.size(); i++)
    {
        char a = s[i];
        if(a-'A'>=0 && a-'A'<26){
            x.push_back(a);
        }
    }
    cout<<x<<"\n";    
    return 0;
}