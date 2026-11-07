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
        ll cnt = 3000;

        // ll x  = 0;
        deque<vll> post(n);
        for (int i = 0; i < n; i++)
        {
            ll tam;cin>>tam;
            for (int j = 0; j < tam; j++)
            {
                ll x;cin>>x;
                post[i].push_back(x);
            }     
            reverse(post[i].begin(),post[i].end());     
        }
        for(auto &v:post){
            set<ll> A;
            vll aux;
            for(auto d:v){
                if(A.find(d) == A.end()){
                    aux.push_back(d);
                    A.insert(d);
                }
            }
            v = aux;
        }
        set<ll> st;
        while (true)
        {
            sort(post.begin(),post.end());
            //     cout<<"--------\n";
            // for(auto v:post){
            //     for(auto a:v)cout<<a<<" ";
            //     cout<<"\n";
            // }
            // cout<<"--------\n";
            while(post.size() && post[0].size()==0){
                post.pop_front();
            }
            if(!post.size())break;
            for(auto x:post[0]){if(st.find(x) == st.end()){cout<<x<<" ";st.insert(x);}}
            // cout<<"\n***\n";
            post.pop_front();
            for (int i = 0; i < post.size(); i++)
            {
                vll aux;
                for(auto d:post[i]){
                    if(st.find(d) == st.end()){
                        aux.push_back(d);
                    }
                }
                post[i] = aux;
            }
            
        }
        cout<<"\n";
        
    }

    return 0;
}