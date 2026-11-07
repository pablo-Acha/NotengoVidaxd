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
        
        string s,c;cin>>s>>c;
        s = '0'+s;
        c = '0'+c;
        ll n = s.size();
        ll r,q;cin>>r>>q;
        queue<ll> qe;
        for (int i = 0; i < r; i++)
        {
            qe.push(0);
        }
        ll cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt+= s[i] != c[i];
        }
        
        for (int i = 0; i < q; i++)
        {
            auto x = qe.front();
            qe.pop();
            if(x!=0){
                if(s[x]!=c[x])cnt++;
            }
            ll f;cin>>f;
            if(f == 1){
                ll pos;cin>>pos;
                if(s[pos]!=c[pos])cnt--;
                qe.push(pos);
                continue;
            }else if(f == 2){
                ll a,pos,b,pos2;cin>>a>>pos>>b>>pos2;
                if(pos == pos2){
                    if(a == 1 && b == 2)swap(s[pos],c[pos2]);
                    else if(a == 2 && b == 1)swap(c[pos],s[pos2]);
                    else if(a == 1 && b == 1)swap(s[pos],s[pos2]);
                    else swap(c[pos],c[pos2]);
                }else{
                    cnt-= s[pos]!=c[pos];
                    cnt-= s[pos2]!=c[pos2];
                    if(a == b){
                        if(a == 1)swap(s[pos],s[pos2]);
                        else swap(c[pos],c[pos2]);
                    }else{
                        if(a == 1)swap(s[pos],c[pos2]);
                        else swap(c[pos],s[pos2]);
                    }
                    cnt+= s[pos]!=c[pos];
                    cnt+= s[pos2]!=c[pos2];
                }
            }else{
                cout<<(cnt>0?"NO\n":"YES\n");
            }
            qe.push(0);
        }
        
        
    }

    return 0;
}