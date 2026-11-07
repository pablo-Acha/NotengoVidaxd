#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

string fun(ll n){
    string s;
    do{
        s.push_back(char(n%10 + '0'));
        n /=10; 
    } while (n);

    return s;
}


string sum(string &s1, string &s2)
{
    ll n = s1.size(),m = s2.size();
    deque<char> dq;
    ll acc = 0;
    for (int i = n - 1, j = m-1; i >= 0 && j>=0; i--,j--)
    {
        ll x = s1[i]-'0';
        ll y = s2[j]-'0';
        ll temp = x+y+acc;
        ll res =temp%10;
        acc = temp/10;
        dq.push_front(char(res+'0'));
    }
    dq.push_front(char(acc+'0'));
    string s;
    while(dq.size()>0 && dq[0] == '0')
    {
        dq.pop_front();
    }    
    for (int i = 0; i < dq.size(); i++)
    {
        s.push_back(dq[i]);        
    }
    if(s.size() == 0)s.push_back('0');
    return s;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        ll tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += s[i]-'0';
        }
        
        for (ll i = n - 1,j = 1; i >= 0; i--,j++)
        {
            tot-=s[i]-'0';
            string s1 =fun(tot); 
            s = sum(s,s1);
        }
        cout<<s<<"\n";
        
        
    }

    return 0;
}