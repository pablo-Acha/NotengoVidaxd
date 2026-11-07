#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()


struct BIT {
    int n;
    vector<long long> bit;

    BIT(int n) : n(n), bit(n, 0) {}

    void update(int i, long long delta) {
        for (; i < n; i = i | (i + 1))
            bit[i] += delta;
    }

    long long query(int i) {
        long long res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1)
            res += bit[i];
        return res;
    }

    long long query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};


struct SegTree {
    int n;
    vector<long long> tree, lazy;

    SegTree(int n) : n(n) {
        tree.assign(4 * n + 5, 0);
        lazy.assign(4 * n + 5, 0);
    }

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        tree[node] += (r - l + 1) * lazy[node];

        if (l != r) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }

        lazy[node] = 0;
    }

    void update(int node, int l, int r,
                int ql, int qr, long long val) {
        push(node, l, r);

        if (r < ql || qr < l) return;

        if (ql <= l && r <= qr) {
            lazy[node] += val;
            push(node, l, r);
            return;
        }

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, r, ql, qr, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

    long long query(int node, int l, int r,
                    int ql, int qr) {
        push(node, l, r);

        if (r < ql || qr < l) return 0;

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        return query(node * 2, l, mid, ql, qr)
             + query(node * 2 + 1, mid + 1, r, ql, qr);
    }

    // Sumar val al rango [l, r]
    void update(int l, int r, long long val) {
        update(1, 1, n, l, r, val);
    }

    // Suma del rango [l, r]
    long long query(int l, int r) {
        return query(1, 1, n, l, r);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;cin>>t;
    while (t--)
    {
        ll n;cin>>n;
        vll arr(n);for(auto &a:arr)cin>>a;
        ll mx = 0;
        ll sum = 0;
        SegTree st(n);
        for (int i = 0; i < n; i++)
        {
            if(arr[i]<mx){
                sum+=st.query(arr[i]+1,mx);
            }
            mx = max(mx,arr[i]);
            st.update(1,arr[i],1);
        }
        
        BIT bit(n+1);
        ll d= 0;
        for (int i = 0; i < n; i++)
        {
            ll temp = bit.query(arr[i],n);
            d = max(d, temp);
            bit.update(arr[i],1);    
        }
        cout<<sum+d<<"\n";
    }
    

    return 0;
}