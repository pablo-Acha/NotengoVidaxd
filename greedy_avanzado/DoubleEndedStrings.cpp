#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;
    while(n--){
        string s;cin>>s;
        string c;cin>>c;
        ll a = s.size();
        ll b = c.size();
        ll mx = 0;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                int h = i;
                int k = j;
                ll aux = 0;
                while (h< a && k < b && s[h] == c[k])
                {
                    aux++;
                    h++;k++;
                }
                mx = max(mx,aux);
            }
        }
        ll res = a+b-(mx*2);
        cout<<res<<"\n";
    }
    return 0;
}