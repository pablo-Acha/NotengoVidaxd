#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll f(string s){
    ll res = 0;
    ll pow = 1;
    for (int i = 0,j = s.size()-1; i < s.size(); i++,j--)
    {
        res+=(s[j]-'0')*pow;
        pow*=10;
    }
    return res;
}

string f1(ll n){
    string s = "";
    while(n){
        ll aux = (n%10)+'0';
        s.push_back(char(aux));
        n/=10;
    }
    if(s.size() == 0){
        s.push_back('0');
        s.push_back('0');
    }else if(s.size() == 1){
        s.push_back('0');
    }
    reverse(s.begin(),s.end());
    return s;
}
bool f2(string s){
    bool f = 1;
    for (int i = 0,j = s.size()-1; i <=j ; i++,j--)
    {
        if(s[i]!=s[j]){f = 0;break;}
    }
    return f;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        string s;cin>>s;
        ll n;cin>>n;
        set<string> st;
        while(st.find(s) == st.end()){
            st.insert(s);
            ll hora = f(s.substr(0,2));
            ll min = f(s.substr(3,2));
            hora= (hora+(n/60))%24;
            min = (min+(n%60));
            if(min>=60){
                hora = (hora+1)%24;
                min = min%60;
            }
            s = f1(hora) +":"+f1(min);
            // cout<<s<<"\n";
        }
        ll res = 0;
        for(auto a:st){
            res+=f2(a);
        }
        cout<<res<<"\n";
    }
    return 0;
}