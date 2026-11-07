#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

bool backTrack(vector<vll> &grid, ll ind, vector<pair<ll,ll>> &pos,
    vector<set<ll>> &row,vector<set<ll>> &colum, vector<set<ll>> &caja, ll n){
        if(ind == pos.size()){
            return true;
        }
        auto [y,x]  = pos[ind];
        bool f= 0;
        vll sig;
        for(auto v:caja[(x/n) + (n*(y/n))]){
            if(colum[x].find(v) != colum[x].end() && row[y].find(v) != row[y].end()){
                sig.push_back(v);
                f = 1;
            }
        }
        if(f){
            for(auto ni:sig){
                caja[(x/n) + (n*(y/n))].erase(ni);
                row[y].erase(ni);
                colum[x].erase(ni);
                grid[y][x] = ni;
                if(!backTrack(grid, ind+1, pos, row,colum, caja, n)){
                    caja[(x/n) + (n*(y/n))].insert(ni);
                    row[y].insert(ni);
                    colum[x].insert(ni);
                    grid[y][x] = 0;
                }else{
                    return true;
                }
            }
            
        }
        return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    bool first = 1;
    while(cin>>n){
        if (!first) cout << '\n';
        first = false;
        ll cu = n*n;
        vector<vll> grid(cu,vector<ll>(cu));
        for (int i = 0; i < cu; i++)
        {
            for (int j = 0; j < cu; j++)
            {
                cin>>grid[i][j];
            }        
        }
        vector<set<ll>> row(cu);
        vector<set<ll>> colum(cu);
        vector<set<ll>> caja(cu);
        vector<pair<ll,ll>> pos;
        for (int i = 0; i < cu; i++)
        {
            for (int j = 1; j <= cu; j++)
            {
                row[i].insert(j);
                colum[i].insert(j);
                caja[i].insert(j);
            }

        }

        bool f = 1;
        for (int i = 0; i < cu; i++)
        {
            for (int j = 0; j < cu; j++)
            {
                if(grid[i][j]!=0)
                {
                    if(row[i].find(grid[i][j])== row[i].end() || colum[j].find(grid[i][j])== colum[j].end()
                        || caja[(j/n) + (n*(i/n))].find(grid[i][j]) == caja[(j/n) + (n*(i/n))].end()){
                            f = 0;
                            break;
                        }
                    row[i].erase(grid[i][j]);
                    colum[j].erase(grid[i][j]);
                    caja[(j/n) + (n*(i/n))].erase(grid[i][j]);
                }else{
                    pos.emplace_back(i,j);
                }
            }        
        }
        if(!f){
            cout<<"NO SOLUTION\n";
            continue;
        }
    
        // if(pos.size() == 0){
        //     for (int i = 0; i < cu; i++)
        //     {
        //         for (int j = 0; j < cu; j++)
        //         {
        //             cout<<grid[i][j]<<" ";
        //         }        
        //         cout<<"\n";
        //     }
        //     return 0;
        // }
        // ll ini = 0;
        // auto [yy,xx]  = pos[ini];
        // bool f= 0;
        // vll sig;
        // for(auto v:caja[(xx/n) + (n*(yy/n))]){
        //     if(colum[xx].find(v) != colum[xx].end() && row[yy].find(v) != row[yy].end()){
        //         f = 1;
        //         sig.push_back(v);
        //         cout<<v<<"\n";
        //         // break;
        //     }
        // }
        // bool si = 0;
        if(backTrack(grid,0, pos, row,colum, caja, n)){
            for (int i = 0; i < cu; i++) {
                for (int j = 0; j < cu; j++) {
                    if (j) cout << ' ';
                    cout << grid[i][j];
                }
                cout << '\n';
            }
        }else{
            cout<<"NO SOLUTION\n";
        }
    }
    return 0;
}