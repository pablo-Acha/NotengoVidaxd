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
        ll n,m,c;cin>>n>>m>>c;
        string s;cin>>s;
        set<ll> st;
        deque<ll> arr;
        for (int i = 0; i < n && st.size()<m; i++)
        {
            if(s[i] == 'I'){
                st.insert(i);
            }
            if(s[i] == 'A')arr.push_back(i);
        }
        ll ap = n+1;
        while(st.size()<m){
            st.insert(ap);
            ap++;
        }
        ll acc = 0;
        priority_queue<pll,vector<pll>,greater<pll>> pq;
        ll res = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(st.find(i)!=st.end()){
                pq.push({min(acc,c-1)+1,i});
                res += min(acc,c-1)+1;
                acc -= min(acc,c-1);
            }else{
                if(s[i] == 'E' ||s[i] == 'A')acc++;
            }  
        }
        ap = n+1;
        while(pq.size()<m){
            pq.push({0,ap});
            ap++;
        }
        // cout<<res<<"\n";
        // for(auto x:st){
        //     cout<<x<<" ";
        // }
        // cout<<"\n";
        while(!pq.empty() && !arr.empty()){
            auto [v,p] = pq.top();
            ll pi = arr[0];
            pq.pop();
            st.erase(p);
            st.insert(pi);
            ll aux = 0;
            acc = 0;
            // for(auto x:st){
            //     cout<<x<<" ";
            // }
            // cout<<"\n";
            for (int i = n - 1; i >= 0; i--)
            {
                if(st.find(i)!=st.end()){
                    // pq.push({min(acc,c),i});
                    aux+= min(acc,c-1)+1;
                    acc -= min(acc,c-1);
                }else{
                    if(s[i] == 'E' ||s[i] == 'A')acc++;
                }
            }
            // cout<<aux<<"\n";
            if(aux>res){
                arr.pop_front();
                res = aux;
            }else {
                st.erase(pi);
                st.insert(p);
            }
            
        }
        // cout<<res<<"\n";
        cout<<res<<"\n";
        
    }
    return 0;
}