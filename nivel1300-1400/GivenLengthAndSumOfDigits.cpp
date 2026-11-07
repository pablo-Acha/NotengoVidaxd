#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
const ll MOD  = 1e9 + 7;
long long restaModular(long long a, long long b) {
    return ((a - b) % MOD + MOD) % MOD;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m;cin>>n>>m;
    string s;
    if(n*9<m || (n > 1 && m  == 0)){
        cout<<-1<<" "<<-1<<"\n";
    }else if(n == 1 && m == 0){
        cout<<0<<" "<<0<<"\n";
    }else{
        for (int i = 0; i < n; i++)
        {
            ll aux = min(9LL,m);
            s.push_back(char(aux+'0'));
            m-= aux;
        }
        string c = s;
        reverse(c.begin(),c.end());
        if(c[0] == '0'){
            c[0] = '1';
            for (int i = 1; i < n; i++)
            {
                if(c[i]> '0' && c[i]<='9'){
                    c[i] = char(c[i]-1);
                    break;
                }
            }
        }
        cout<<c<<" "<<s<<"\n";
    }
    
    return 0;
}