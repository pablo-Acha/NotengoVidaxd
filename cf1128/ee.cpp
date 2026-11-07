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
        ll n,k;cin>>n>>k;
        string s;cin>>s;
        s = '('+ s;
        stack<ll> st;
        vll pa(n+1);
        vll dist(n+1);
        st.push(0);
        for (int i = 1; i <= n; i++)
        {
            if(s[i] == '('){
                pa[i] = st.top();
                dist[i] = (i-pa[i]-1)/2;
                st.push(i);
            }else{
                st.pop();
            }
        }
        vll res(n);
        ll act = k;
        ll acc = 0;
        for (int i = 1; i <= n; i++)
        {
            if(s[i] == ')')continue;
            if(dist[i]>act){
                act = k;
                acc = 0;
            }else{
                act-=dist[i];
                acc = res[pa[i]];
            }
            res[i] = acc++;
        }
        
    }

    return 0;
}