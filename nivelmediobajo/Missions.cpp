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
    ll n;cin>>n;
    vector<pair<ll,ll>> arr(n);
    for (int i = 0; i < n; i++)
    {
        auto &[a,b] = arr[i];
        cin>>b>>a;
    }
    sort(arr.begin(),arr.end());
    ll acc = 0;
    bool f = 1;
    for (int i = 0; i < n; i++)
    {
        acc+=arr[i].second;
        if(acc>arr[i].first ){
            f = 0;
            break;
        }
    }
    cout<<(f?"Yes\n":"No\n");
    return 0;
}