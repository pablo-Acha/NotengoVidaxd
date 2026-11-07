#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

template <typename T = long long>

struct FenwickTree {
    int n;
    vector<T> bit;

    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    FenwickTree(const vector<T>& a) : FenwickTree(a.size()) {
        for (int i = 1; i <= n; i++) {
            bit[i] += a[i - 1]; 
            int parent = i + (i & -i);
            if (parent <= n) {
                bit[parent] += bit[i];
            }
        }
    }

    void add(int idx, T val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    void set(int idx, T val, const vector<T>& current_array) {
        T diff = val - current_array[idx - 1];
        add(idx, diff);
    }

    T query(int idx) const {
        T sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    T query_range(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;cin>>t;
    while(t--){
        ll n,q;cin>>n>>q;
        vll arr(n+1);
        vector<vll> dp(n+1);
        vll f(n+1);
        for (int i = 1; i <= n; i++)
        {
            cin>>arr[i];
            ll aux = arr[i];
            dp[i].push_back(arr[i]);
            while(true){
                ll tem = 0;
                while(aux){
                    tem += aux%10;
                    aux/=10;
                }           
                aux = tem;
                dp[i].push_back(aux);     
                if(aux/10 ==0)break;
            }
        }
        
        // for(auto v:dp){
        //     for(auto x:v)cout<<x<<" ";cout<<"\n";
        // }
        // cout<<"-----\n";
        FenwickTree<ll> ft(f);
        for (int i = 0; i <q; i++)
        {
            ll a;cin>>a;
            if(a == 1){
                ll l,r;cin>>l>>r;
                ft.add(r,1);
                if(l>1)ft.add(l-1,-1);
                // for (int i = 0; i <= n; i++)
                // {
                //     cout<<ft.query_range(i,i)<<" ";
                // }cout<<"\n";
                
            }else{
                ll x;cin>>x;
                ll cnt = ft.query_range(x,n);
                
                if(cnt>=dp[x].size()){
                    cout<<dp[x][dp[x].size()-1]<<"\n";
                } else{
                    cout<<dp[x][cnt]<<"\n";
                }
            }
        }
        
    }
    

    return 0;
}