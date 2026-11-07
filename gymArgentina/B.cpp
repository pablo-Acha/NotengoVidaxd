#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin>>s;

    string lu;

    set<string> res;
    set<char> voc = {'A','E','I','O','U'};
    if(s.size()<=4){
        cout<<"-\n";
        return 0;
    }
    for (ll i = 1; i < s.size()-3; i++)
    {   
        // cout<<s.substr(i,3)<<"\n";
        if(s.substr(i,3) == "GAS" && s[i-1] == s[i+3] && voc.find(s[i-1]) !=voc.end()){
            string c = s;
            c.erase(i,4);
            res.insert(c);
            // cout<<c<<"\n";
        }
    }
    if(res.size() == 0){
        cout<<"-\n";
    }else if(res.size() == 1){
        cout<<*res.begin()<<"\n";
    }else{
        cout<<"+\n";
    }
    

    return 0;
}