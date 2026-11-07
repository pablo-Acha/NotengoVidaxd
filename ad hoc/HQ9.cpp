#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<long long> vll;
void pr(vll &arr){for(auto a:arr)cout<<a<<"\n";cout<<"\n";}
int main(){
    string s;cin>>s;
    bool f = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] == 'H' ||s[i] == 'Q' || s[i] == '9'){
            f = 1;
            break;
        }
    }
    cout<<(f?"YES":"NO")<<"\n";
    return 0;
}