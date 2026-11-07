#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

vll dx = {-1,0,1,0};
vll dy = {0,-1,0,1};

struct Estado{
    set<pair<ll,ll>> pos;
    ll cont;
    ll y;
    ll x;
    // bool operator<(const Estado& other) const {
    //     if (cont != other.cont)
    //         return cont < other.cont;
    //     return pos < other.pos;
    // }
};

void bfs(set<set<pair<ll,ll>>> &st,vector<string> &vs, ll y, ll x,ll k, ll n,ll &res){
    queue<Estado> qu;
    Estado in = {{{y,x}},1};
    qu.push(in);
    // ll res = 0;
    while(!qu.empty()){
        Estado r = qu.front();
        qu.pop();
        ll xx = r.x;
        ll yy = r.y;
        for(auto [le,ri]:r.pos){
                cout<<" |"<<le<<" "<<ri<<"| ";
            }
            cout<<"\n";
        if(r.cont == k){
            res++;
            
            continue;
        } 
        for (int i = 0; i < 4; i++)
        {
            ll nx = xx +dx[i];
            ll ny = yy +dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<n && vs[ny][nx] == '.'){
                Estado nue = {r.pos,0,ny,nx};
                nue.pos.insert({ny,nx});
                nue.cont = nue.pos.size();
                if(st.find(nue.pos) != st.end())continue;
                st.insert(nue.pos);
                qu.push(nue);
            }
        }  
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k;cin>>n>>k;
    vector<string> vs(n);
    set<set<pair<ll,ll>>> st;
    for (int i = 0; i < n; i++)
    {
        cin>>vs[i];
    }
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(vs[i][j] == '.')bfs(st,vs,i,j,k,n,res);
        }        
    }
    cout<<res<<"\n";
    

    return 0;
}