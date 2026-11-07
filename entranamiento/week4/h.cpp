
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;

struct Fenwick {
    int n;
    vll bit, arr;

    Fenwick(int n) : n(n), bit(n, -INF), arr(n, -INF) {}

    void update(int i, ll val) {
        arr[i] = max(arr[i], val);
        while (i < n) {
            bit[i] = max(bit[i], val);
            i = i | (i + 1);
        }
    }

    ll query(int l, int r) {
        ll res = -INF;

        while (r >= l) {
            int ini = r & (r + 1);

            if (ini >= l) {
                res = max(res, bit[r]);
                r = ini - 1;
            } else {
                res = max(res, arr[r]);
                r--;
            }
        }

        return res;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;cin>>n;
    vll arr(n);
    vll brr(n);
    for(auto &x:arr)cin>>x;
    for(auto &x:brr)cin>>x;
    vll temp = arr;
    sort(all(temp));
    temp.erase(unique(all(temp)), temp.end());
    vll aux(temp.size());    
    Fenwick seg_tree(temp.size());
    ll t = -1;
    vll tiempo(n);
    tiempo[0] = 0;
    seg_tree.update(lower_bound(all(temp),arr[0])-temp.begin(),arr[0]+brr[0]);
    for (int i = 1; i < n; i++)
    {
        ll pos = lower_bound(all(temp),arr[i])-temp.begin();
        ll r =seg_tree.query(0,pos); 
        if(r<=tiempo[i-1]+1){
            tiempo[i]= tiempo[i-1]+1;
        }else{
            tiempo[i] =r;
        }        
        seg_tree.update(pos,tiempo[i]+arr[i]+brr[i]);
    }
    ll res = seg_tree.query(0,temp.size()-1);
    cout<<res<<"\n";


    return 0;
}


