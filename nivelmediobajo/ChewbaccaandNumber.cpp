#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
// #include <iomanip>

int main(){
    string s;cin>>s;
    for (int i = 0; i < s.size(); i++)
    {
        if((s[i]-'0') >=5){
            s[i] = char((9-(s[i]-'0'))+'0');
        }
    }
    if(s[0] == '0'){
        s[0] ='9';
    }
    cout<<s<<"\n";
    return 0;
}