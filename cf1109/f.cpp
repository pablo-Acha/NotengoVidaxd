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
        vll numh(n);
        vll pa(n);
        vector<vll> arbol(n);
        for (int i = 1; i < n; i++)
        {
            cin>>pa[i];
            pa[i]--;
            numh[pa[i]]++;
            arbol[pa[i]].push_back(i);
        }
        
        // for(auto &a:pa){cin>>a,a--;numh[a]++;}
        vector<pair<ll,ll>> rang(n,{1e9,1e9*-1});
        vll hojas(n);for(auto &a:hojas){cin>>a;}
        queue<ll> qu;
        for (int i = 0; i < n; i++)
        {
            if(hojas[i] !=0){
                rang[i] = {hojas[i],hojas[i]};
                qu.push(i);
            }
        }
        while(!qu.empty()){
            ll ind = qu.front();
            auto [l,r]= rang[ind];
            qu.pop();
            if(ind == 0)break;
            ll pap =pa[ind];
            auto &[nl,nr] = rang[pap];
            nl =min(nl,l);
            nr =max(nr,r);
            numh[pap]--;
            if(numh[pap] ==  0){
                qu.push(pap);
            }
        }
        // for(auto [l,r]:rang){
        //     cout<<l<<" "<<r<<"\n";
        // }
        qu = queue<ll>();
        qu.push(0);
        bool f = 1;
        while(!qu.empty()){
            ll nodo = qu.front();
            qu.pop();
            ll err = 0;
            ll tam= arbol[nodo].size();
            if(tam>1)for (int i = 0; i < tam; i++)
            {
                auto [l,r] =rang[arbol[nodo][i]]; 
                auto [al,ar] =rang[arbol[nodo][(i-1+tam)%tam]]; 
                if(l<ar)err++;
            }
            if(err>1){f = 0;break;}
            for(auto ni:arbol[nodo]){
                qu.push(ni);
            }
        }
        if(f){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }

    return 0;
}