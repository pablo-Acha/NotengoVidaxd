#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    string s;cin>>s;
    bool f = 0;
    for (int i = 0; i < s.size()-1; i++)
    {
        if(s[i] == 's' && s[i+1] == 's'){
            f = 1;
            break;
        }
    }
    cout<<(f?"hiss":"no hiss") <<"\n";   
    return 0;
}   