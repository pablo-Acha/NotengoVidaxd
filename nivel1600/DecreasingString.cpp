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

    ll t;cin>>t;
    while(t--){
        deque<char> iz,der;
        string s;cin>>s;
        ll n;cin>>n;
        if(s.size() == 1){
            cout<<s[0];
            continue;
        }
        s.push_back(char('a'-1));
        for (int i = 0; i < s.size(); i++)
        {
            der.push_back(s[i]);
        }
        ll m =der.size();
        ll ini = 1,fn = m-1, aux = m-1;
        // cout<<ini<<" "<<fn<<"\n";
        iz.push_back(char('a'-1));
        while (true)
        {
            if(n>=ini&& n<=fn){
                break;
            }else{
                if(iz.back()>der.front()){
                    ini+=aux;
                    aux--;
                    fn+=aux;
                    iz.pop_back();
                }else{
                    iz.push_back(der.front());
                    der.pop_front();
                }
            }
        }
        deque<char> c;
        for(auto x:iz)c.push_back(x);
        for(auto x:der)c.push_back(x);
        c.pop_back();
        c.pop_front();
        // cout<<ini<<" "<<fn<<"\n";
        n-= ini;
        cout<<c[n];
        
    }

    return 0;
}