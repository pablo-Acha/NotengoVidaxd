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
            ll n,m;cin>>n>>m;
            string s;cin>>s;
            s = '-'+s;
            vll unos(s.size()),ceros(s.size());
            
            for (int i = 1, last = 0; i <= n; i++)
            {
                last = s[i] == '0'? i:last;
                ceros[i] = last;
            }
            for (int i = n, last = n+1; i >= 1; i--)
            {
                last = s[i] == '1'?i:last;
                unos[i] = last;
            }
            // for(auto x:unos)cout<<x<<" ";cout<<"\n";
            // for(auto x:ceros)cout<<x<<" ";cout<<"\n";
            set<pll> st;
            for (int i = 0; i < m; i++)
            {
                ll l,r;cin>>l>>r;
                ll left = unos[l];
                ll right = ceros[r];
                // cout<<left<<" "<<right<<"\n";
                if(left>= l && l<=right && right<=r && r>= left && left<right){
                    st.insert({left,right});
                }else{
                    st.insert({0,n+1});
                }
            }
            cout<<st.size()<<"\n";
            

            
            
        }


        return 0;
    }