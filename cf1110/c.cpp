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
        set<ll> st;
        deque<ll> res;
        bool f = 1;
        for (int i = 0; i < n; i++)
        {
            st.insert(i);
        }
        ll x = n^k;
        ll j = 0;
        while(x){
            ll aux = 0;
            if(x&1){
                aux= 1<<j;
            }
            j++;
            x/=2;
            if(aux && st.find(aux)!=st.end()){
                res.push_back(aux);
                st.erase(aux);
            }else if(aux){
                f = 0;
                break;
            }
        }
        if(!f){
            cout<<"NO\n";
        }else{
            for(auto x:st){
                res.push_front(x);
            }
            // reverse(all(res));
            cout<<"YES\n";
            for(auto a:res){
                cout<<a<<" ";
            }
            cout<<"\n";
        }
        
    }

    return 0;
}