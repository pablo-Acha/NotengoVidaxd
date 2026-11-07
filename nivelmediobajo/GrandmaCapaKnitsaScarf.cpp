#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        string s;cin>>s;
        set<char> st;
        vector<char> fin;
        for (int i = 0; i < n; i++)
        {
            if(st.find(s[i]) == st.end()){
                st.insert(s[i]);
                string c = "";
                for (int j = 0; j < n; j++)
                {
                    if(s[j] == s[i])continue;
                    c.push_back(s[j]);
                }
                bool f = 1;
                for (int h = 0,j = c.size()-1; h <=j ; h++,j--)
                {
                    if(c[h]!=c[j]){f = 0;break;}
                }
                if(f){
                    fin.push_back(s[i]);
                }
            }
        }
        ll res = 1e9;
        for (int i = 0; i < fin.size(); i++)
        {
            ll aux = 0;
            for (int j = 0,h = s.size()-1; j <=h; j++,h--)
            {
                if(s[j]!=s[h]){
                    aux++;
                    if(s[j] == fin[i]){
                        j++;
                    }else{
                        h--;
                    }
                    j--;
                    h++;
                }
            }
            // cout<<i<<" "<<aux<<"\n";
            res = min(aux,res);
        }
        if(res == 1e9){
            cout<<-1<<"\n";
        }else{
            cout<<res<<"\n";
        }
        
    }
    return 0;
}