#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


ll dist(ll ax,ll bx, ll ay, ll by){
    return abs(ax-bx)+abs(ay-by);
}

const ll INF = 1e18;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while (t--)
    {
        ll n,ax,ay,bx,by;
        cin>>n>>ax>>ay>>bx>>by;
        set<ll> aux;
        vector<pll> temp(n);
        set<ll> st;
        for (int i = 0; i < n; i++)
        {
            auto &[x,_] = temp[i];
            cin>>x;
            st.insert(x);
        }
        for (int i = 0; i < n; i++)
        {
            auto &[_,y] = temp[i];
            cin>>y;
        }
        temp.push_back({ax,ay});
        temp.push_back({bx,by});
        for(auto [x,y]:temp){
            st.insert(x);
        }
        vll ind;
        for(auto x:st)ind.push_back(x);
        vector<vll> Y(st.size(),vll(2));
        vector<vll> dp(st.size(),vll(2));
        vll X(st.size());

        for(int i = 0;i<Y.size();i++)Y[i][0] = INF,Y[i][1] =-INF;
        for (int i = 0; i < temp.size(); i++)
        {
            auto [x,y] = temp[i];
            ll p = lower_bound(all(ind),x)-ind.begin();
            X[p] = x;
            Y[p][0] = min(y,Y[p][0]); 
            Y[p][1] = max(y,Y[p][1]); 
        }
        for (int i = 1; i < dp.size(); i++)
        {
            ll c = abs(Y[i][0]-Y[i][1]);
            ll aux = min(dist(X[i-1],X[i],Y[i-1][0],Y[i][1])+dp[i-1][0],dist(X[i-1],X[i],Y[i-1][1],Y[i][1])+dp[i-1][1]);
            dp[i][0] = aux+c;
            aux = min(dist(X[i-1],X[i],Y[i-1][0],Y[i][0])+dp[i-1][0],dist(X[i-1],X[i],Y[i-1][1],Y[i][0])+dp[i-1][1]);
            dp[i][1] = aux+c;
        }
        // for(auto s:X)cout<<s<<" ";cout<<"\n";
        // for(auto s:dp)cout<<s[0]<<" ";cout<<"\n";
        cout<<min(dp[dp.size()-1][1],dp[dp.size()-1][0])<<"\n";
    }
    

    return 0;
}