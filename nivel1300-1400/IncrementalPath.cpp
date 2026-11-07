#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;

ll guas(ll n){return n*(n+1) /2;}

const ll MOD = 998244353;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,m;cin>>n>>m;
        string s;cin>>s;
        set<ll> st;
        for (int i = 0,a; i < m; i++)
        {
            cin>>a;
            st.insert(a);
        }
        set<ll> pr;
        ll blanco = 2;
        for(auto a:st){
            if(a == 1)continue;
            if(blanco == a){
                blanco++;
            }else{
                pr.insert(blanco);
                blanco =a+1;
            }

        }
        pr.insert(blanco);
        
        // for(auto a:pr){
        //     cout<<a<<" ";
        // }
        // cout<<"\n";
        ll act = 1;
        for (int i = 0; i < n; i++)
        {
            if(s[i] == 'A'){
                act++;
                if(st.find(act) == st.end()){
                    st.insert(act);
                    if(act == *pr.begin()){
                        pr.erase(pr.begin());
                    }
                    if(st.find(act+1) == st.end() && (pr.empty() ||act+1!=*pr.begin())){
                        pr.insert(act+1);
                    }
                }
            }else{
                act = *pr.begin();
                pr.erase(pr.begin());
                // cout<<act<<" "<<i<<"\n";
                if(st.find(act) == st.end()){
                    st.insert(act);
                    if(st.find(act+1) == st.end()&& (pr.empty() ||act+1!=*pr.begin())){
                        pr.insert(act+1);
                    }
                }
                act= *pr.begin();
                pr.erase(pr.begin());
                if(st.find(act+1) == st.end()&& (pr.empty() ||act+1!=*pr.begin())){
                    pr.insert(act+1);
                }
            }
            // cout<<act<<" "<<i<<"\n";
        }
        cout<<st.size()<<"\n";
        for(auto a:st){
            if(a == 0)continue;
            cout<<a<<" "; 
        }
        cout<<"\n";
    }

    return 0;
}