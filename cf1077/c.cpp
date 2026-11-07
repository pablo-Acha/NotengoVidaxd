#include<bits/stdc++.h>
using namespace std;
#define rnl "\n"
typedef long long ll;
typedef vector<ll> vll;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]); 
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; 
        if (sz[a] < sz[b]) swap(a, b); 
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int size(int x) {
        return sz[find(x)];
    }
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        vll brr = arr;
        sort(brr.begin(),brr.end());
        vll per;
        map<ll,vll> mp;
        for (int i = 0; i < n; i++)
        {
            if(brr[i]!=arr[i]){
                per.push_back(arr[i]);
                mp[arr[i]].push_back(brr[i]);
            }
        }
        sort(per.begin(),per.end());
        vector<set<ll>> vst;
        map<ll,bool> vis;
        for (int i = 0; i < per.size(); i++)
        {
            if(vis.find(per[i])!=vis.end())continue;
            stack<ll> pila;
            pila.push(per[i]);
            set<ll> aux;
            vis[per[i]] = 1;
            while (!pila.empty()){
                ll nodo = pila.top();
                pila.pop();
                for(auto ni:mp[nodo]){
                    if(aux.find(ni)!=aux.end())continue;
                    vis[ni] = 1;
                    aux.insert(ni);
                    pila.push(ni);
                }
            }
            vst.push_back(aux);
        }
        if(vst.size()>1){
            ll mn = per[0];
            ll mx = per[per.size()-1];
            ll ayuda = 1e9+7;
            for (int i = 0; i < vst.size(); i++)
            {
                auto p = vst[i].end();
                p--;
                ll fin = *p;
                ll ini = *vst[i].begin();
                ll aa = max(abs(fin-mn),abs(ini-mx));
                ayuda = min(ayuda,aa);
            }
            // cout<<mx<<" "<<mn<<" "<<ayuda<<" ";
            ll dif = 1e9+5;
            for (int i = 0; i < per.size(); i++)
            {
                ll pa = max(abs(per[0]-per[i]),abs(per[i]-per[per.size()-1]));            
                dif = min(dif,pa);
            }
            ll res = min(dif,ayuda);
            cout<<res<<rnl;
        }else{
            ll dif = 1e9+5;
            if(per.size() == 0){
                cout<<-1<<rnl;
                continue;
            }
            for (int i = 0; i < per.size(); i++)
            {
                ll pa = max(abs(per[0]-per[i]),abs(per[i]-per[per.size()-1]));            
                dif = min(dif,pa);
            }
            // cout<<dif<<" "<<ayuda<<rnl;
            // ll res = min(dif,ayuda);
            cout<<dif<<rnl;

        }

        
    }
    
    return 0;
}