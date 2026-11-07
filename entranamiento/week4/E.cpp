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
    for (ll i = 0; i < s.size(); i++)
    {
        string aux = s.substr(i,6);
        // cout<<"asdasdssad "<<aux;
        if(aux == "mesero"){
            lu.push_back('t');
            lu.push_back('a');
            lu.push_back('q');
            lu.push_back('u');
            lu.push_back('e');
            lu.push_back('r');
            lu.push_back('o');
            i+=5;
        }else{
            lu.push_back(s[i]);
        }
    }

    cout<<lu;
    
}