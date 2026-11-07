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
        ll n;cin>>n;
        string s;cin>>s;
        if(n == 1){
            cout<<1<<"\n";
            continue;
        }
        vector<pair<set<char>,set<char>>> normal(n);
        set<char> odd;
        set<char> even;
        for (int i = 0; i < n; i++)
        {
            if(i&1){
                even.insert(s[i]);
            }else{
                odd.insert(s[i]);
            }
            normal[i] = {odd,even};
        }

        if(n&1){
            vector<pair<set<char>,set<char>>> dp(n);
            dp[0] = normal[0];
            dp[1].first.insert(s[1]);
            for (int i = 2; i < n; i++)
            {
                auto [od,ev] = normal[i-2];
                auto [xod,xev] = dp[i-1];
                if(i&1){
                    //par
                    ll tam1 = od.size()+ev.size()+(od.find(s[i]) == od.end());
                    ll tam2 = xod.size()+xev.size()+(xod.find(s[i]) == xod.end());
                    if(tam1<tam2){
                        dp[i] = normal[i-2];
                    }else{
                        dp[i] = dp[i-1];
                    }
                    dp[i].first.insert(s[i]);
                }else{
                    ll tam1 = od.size()+ev.size()+(ev.find(s[i]) == ev.end());
                    ll tam2 = xod.size()+xev.size()+(xev.find(s[i]) == xev.end());
                    if(tam1<tam2){
                        dp[i] = normal[i-2];
                    }else{
                        dp[i] = dp[i-1];
                    }
                    dp[i].second.insert(s[i]);
                }
                
            }
            for (int i = 0; i < n; i++)
            {
                auto [od,ev] = normal[i];
                auto [xod,xev] = dp[i];
                cout<<" |"<<xod.size()<<" , "<<xev.size()<<"| ***** |"<<od.size()<<" , "<<ev.size()<<"| \n";
            }
            


            auto [od,ev] = normal[n-2];
            auto [xod,xev] = dp[n-1];
            
            ll tam1 = od.size()-1+ev.size()-1;
            ll tam2 = xod.size()-1+xev.size()-1;
            cout<<tam1<<" "<<tam2<<"\n";
            cout<<min(tam1,tam2)+1LL<<"\n";
        }else{            
            ll res = (odd.size()-1)+(even.size()-1);
            cout<<res<<"\n";
        }
    }

    return 0;
}