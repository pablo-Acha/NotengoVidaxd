#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> p, sz;
    int components;

    DSU(int n){
        p.resize(n);
        sz.resize(n,1);
        iota(p.begin(),p.end(),0);
        components = n;
    }

    int find(int x){
        if(p[x]==x) return x;
        return p[x]=find(p[x]);
    }

    void unite(int a,int b){
        a=find(a);
        b=find(b);

        if(a==b) return;

        if(sz[a] < sz[b]) swap(a,b);

        p[b]=a;
        sz[a]+=sz[b];
        components--;   // se reduce el número de conjuntos
    }

    int count_sets(){
        return components;
    }
};

int main(){
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        DSU uf(n);
        for (int i = 0,a,b; i < m; i++)
        {
            cin>>a>>b;
            a--;b--;
            uf.unite(a,b);
        }
        cout << uf.count_sets() << endl;
    }
}