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
        ll n,a,b;cin>>n>>a>>b;
        string s;cin>>s;
        ll acc = 0,potencial=0;
        vll ind,val;
        ll cnt = 0, aux = 0;
        for (int i = 0; i < n; i++)
        {
            if(s[i]  == 'I'){
                acc+= max(potencial,0LL);
                if(ind.size()){
                    val.push_back(aux);
                }
                if(ind.size()<a){
                    aux = 0;
                    potencial-=b-1;
                    ind.push_back(i);
                }
            }else{
                aux++;
                potencial++;
            }
        }
        val.push_back(aux);
        for (int i = ind.size(); i <= a; i++)
        {
            ind.push_back(n);
            val.push_back(0);
        }
        ll l= 0,r = val.size()-1;
        while(l<ind[r])
        {
            if(s[l] == 'A'){
                val[r] = val[r]+acc - b;
            }
            if(s[l]!='I'){
                acc--;
            }
            l++;
        }
        
        
        
        
        
 
    }

    return 0;
}