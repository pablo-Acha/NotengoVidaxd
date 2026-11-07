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
        ll n,m,v;cin>>n>>m>>v;
        vll arr(n);for(auto &a:arr)cin>>a;
        arr.push_back(0);
        vll aux(m+1),ind(m+1),top(m+1);
        ll act = 0;
        ll j = 0;
        ll left = 0;
        for (int i = 0;i < n && j<m; i++)
        {
            act+=arr[i];
            if(act >=v){
                aux[j] = act;
                ind[j] = left;
                left = i+1;
                top[j] = left;
                j++;
                act = 0;
            }
        }
        top[m] = n+1;
        if(j<m){
            cout<<"-1\n";
            continue;
        }
        ind[j]= left;
        while(left<n+1){aux[j]+=arr[left];left++;}
        
        ll res= aux[m];
        for (int i = m - 1; i >= 0; i--)
        {
            // cout<<i<<"\n";
            if(aux[i+1] >v){
            // cout<<i<<"\n";
                ll h = ind[i+1];
                while(h<top[i+1] &&aux[i+1]>v && !(aux[i+1]-arr[h]<v)){
                    aux[i+1]-=arr[h];
                    aux[i]+=arr[h];
                    h++;
                }
                top[i] = h+1;
            }else if(aux[i+1] <v){
                ll h = ind[i+1]-1;
                while(h>ind[i] && aux[i+1]<v ){
                    aux[i+1]+=arr[h];
                    aux[i]-=arr[h];
                    h--;
                }
                top[i]= h;
            }
            // cout<<i<<"\n";
            // for(auto x:aux)cout<<x<<" ";cout<<"\n";
            if(aux[i+1]<v)break;
            res= max(aux[i],res);
        }
        cout<<res<<"\n";
    }

    return 0;
}