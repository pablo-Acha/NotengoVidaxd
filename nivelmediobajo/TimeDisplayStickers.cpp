#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


bool hora(multiset<ll> &mt){
    if(mt.empty())return false;
    auto p = mt.begin();
    ll val = *p;
    mt.erase(p);
    if(val == 1)
    {
        auto m = mt.upper_bound(1);
        if(m == mt.begin())return false;
        m--;mt.erase(m);
    }else if(val == 0){
        auto m = mt.upper_bound(9);
        if(m == mt.begin())return false;
        m--;mt.erase(m);
    }else{
        return false;
    }
    return true;
}
bool minuto(multiset<ll> &mt){
    
    auto p = mt.upper_bound(5);
    if(p == mt.begin())return false;
    p--;mt.erase(p);
    auto m = mt.upper_bound(9);
    if(m == mt.begin())return false;
    m--;mt.erase(m);
    return true;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        multiset<ll> x;
        for (int i = 0; i < n; i++)
        {
            x.insert(s[i]-'0');
        }
        ll cnt = 0;
        while(hora(x) && minuto(x)){
            cnt++;
        }
        cout<<cnt<<"\n";
    }

    return 0;
}