#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

ll g(ll n){
    return (n*(n+1))/2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        if(n == 1){
            cout<<1<<" "<<1<<"\n";
            cout<<1<<" "<<1<<" "<<1<<"\n";
        }else{
            ll h = n,v = n;
            bool f = 1;
            vector<vll> res;
            ll sum = 0;
            for (int i = 0; i < n; i++)
            {
                vll aux;
                aux.push_back(1);
                aux.push_back(i+1);
                for (int j = 0; j < n; j++)
                {
                    aux.push_back(j+1);
                    sum+= j+1;
                }
                res.push_back(aux);
            }
            ll cnt = n;
            // cout<<sum<<"----\n";
            while(cnt<2*n){
                if(h <= 1 && v <= 1)break;
                if(f)
                {
                    for (int i = 1; i <= h; i++)
                    {
                        if(cnt== 2*n)break;
                        ll act = i*v;
                        // cout<<i<<" "<<g(v)<<" "<<act<<"\n";
                        if(g(v)>=act){
                            vll aux;
                            aux.push_back(2);
                            aux.push_back(i);
                            sum-= act;
                            // cout<<sum<<"----\n";

                            for (int j = 0; j < n; j++)
                            {
                                aux.push_back(j+1);
                                sum+= j+1;
                            }
                            // cout<<sum<<"----\n";
                            res.push_back(aux);
                        }else{
                            h = i-1;
                            break;
                        }
                        cnt++;
                    }
                    f = 0;
                }else{
                    for (int i = 1; i <= v; i++)
                    {
                        if(cnt== 2*n)break;
                        ll act = i*h;
                        if(g(h)>=act){
                            sum-=act;
                            vll aux;
                            aux.push_back(1);
                            aux.push_back(i);
                            for (int j = 0; j < n; j++)
                            {
                                sum+= act;
                                aux.push_back(j+1);
                            }
                            res.push_back(aux);
                        }else{
                            v = i-1;
                            break;
                        }
                        cnt++;
                    }
                    f = 1;
                }
            }
            cout<<sum<<" "<<res.size()<<"\n";
            for(auto v:res){
                for(auto x:v){
                    cout<<x<<" ";
                }
                cout<<"\n";
            }
                      



        }
    }

    return 0;
}