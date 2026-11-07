#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


bool dfs1(ll x,ll y, vector<string> &s,set<pll> st){
    ll n = s.size();
    st.erase({x,y});
    for (int i = x+1; i < n && y>=0; i++)
    {
        st.erase({i,y});
        y--;
        st.erase({i,y});
    }
    return st.empty();   
}

bool dfs2(ll x,ll y, vector<string> &s,set<pll> st){
    ll n = s.size();
    st.erase({x,y});
    y--;
    st.erase({x,y});
    for (int i = x+1; i < n && y>=0; i++)
    {
        st.erase({i,y});
        y--;
        st.erase({i,y});
    }
    return st.empty();   
}
bool dfs3(ll x,ll y, vector<string> &s,set<pll> st){
    ll n = s.size();
    st.erase({x,y});
    y++;
    st.erase({x,y});
    for (int i = x+1; i < n && y<n; i++)
    {
        st.erase({i,y});
        y++;
        st.erase({i,y});
    }
    return st.empty();   
}
bool dfs4(ll x,ll y, vector<string> &s,set<pll> st){
    ll n = s.size();
    st.erase({x,y});
    for (int i = x+1; i < n && y<n; i++)
    {
        st.erase({i,y});
        y++;
        st.erase({i,y});
    }
    // for(auto [x,y]:st)cout<<x<<" "<<y<<"\n";
    return st.empty();   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vector<string> m(n);
        for (int i = 0; i < n; i++)
        {
            cin>>m[i];
        }
        ll x = n,y = n,xx = n, yy = n;
        bool f = 1;
        vll ys(n),xs(n);
        set<pll> st;
        for (int i = n - 1; i >= 0 && f; i--)
        {
            bool f1 = 0;
            ll h = n;
            for (int j = 0; j < n && f; j++)
            {
                if(m[i][j] == '#'){
                    st.emplace(j,i);
                    if(f1 && j-1 != h){
                        f = 0;
                        break;
                    }else if(f1){
                        continue;
                    }
                    h = j;
                    f1 = 1;
                }
            }
        }

        for (int i = n - 1; i >= 0 && f; i--)
        {
            bool f1 = 0;
            ll h = n;
            for (int j = 0; j < n && f; j++)
            {
                if(m[j][i] == '#'){
                    xx = i;
                    yy = j;
                    if(f1 && j-1 != h){
                        f = 0;
                        break;
                    }else if(f1){
                        continue;
                    }
                    x = i;
                    y = j;
                    h = j;
                    f1 = 1;
                }
            }
        }
        // cout<<x<<" "<<y<<"\n";
        if(!f){
            cout<<"NO\n";
        }else{
            bool f =0;
            // for(auto [y,x]:st){
            //     cout<<y<<" "<<x<<"\n";
            // }
            f = dfs1(x,y,m,st)  || dfs2(x,y,m,st) || dfs3(x,y,m,st)|| dfs4(x,y,m,st);
            f |= dfs1(xx,yy,m,st)  || dfs2(xx,yy,m,st) || dfs3(xx,yy,m,st)|| dfs4(xx,yy,m,st);
            if(!f && st.size() == 4){
                for (int i = 0; i < n-1 && !f; i++)
                {
                    for (int j = 0; j < n-1; j++)
                    {
                        if(m[i][j] == '#' && m[i][j+1] == '#' &&
                            m[i+1][j] == '#' && m[i+1][j+1] =='#'){
                                f = 1;
                                break;
                        }
                    }                    
                }                
            }
            cout<<(f?"YES\n":"NO\n");
        }
    }

    return 0;
}