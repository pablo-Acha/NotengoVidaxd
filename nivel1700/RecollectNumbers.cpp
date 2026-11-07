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
        if(k<n || k>(2*n)-1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            while(2*n-1!= k){
                cout<<n<<" "<<n<<" ";
                n--,k--;
            }
            if(n == 1){
                cout<<n<<" "<<n<<"\n";
            }else{
            // cout<<"----\n";
                vll arr(2*n);
                arr[0] = 1;
                arr[1] = 2;
                set<ll> st;
                for (int i = 1; i <= n; i++)
                {
                    st.insert(i);
                }
                for (int i = 3,j = 2; i <= n; i++,j+=2)
                {
                    arr[j] = i;
                }
                for (int i = 0; i < 2*n; i++)
                {
                    if(arr[i] == 0){
                        arr[i] = *st.begin();
                        st.erase(st.begin());
                    }
                }
                for(auto x:arr)cout<<x<<" ";cout<<"\n";
                // for (int i = 0; i < arr.size(); i++)
                // {
                //     cout<<arr[i]<<" ";
                // }
                // cout<<"\n";
            }
            
        }
    }

    return 0;
}