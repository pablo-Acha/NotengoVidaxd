#include<bits/stdc++.h>

using namespace std;

struct SegmentTree {
    vector<int> st;
    int n;
    SegmentTree(int n_): n(n_) {
        st.resize(4 * n);
        build(1, 0, n);
    }

    void build(int node, int l, int r) {
        if (r - l == 1) {
            st[node] = 1;
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid, r);
        st[node] = st[2 * node] + st[2 * node + 1];
    }

    int kth(int node, int l, int r, int k) {
        if (r - l == 1) { 
            st[node] = 0;
            return l + 1;
        }
        int mid = l + (r - l) / 2;
        int left = st[2 * node];
        int res;
        if (k <= left) res = kth(2 * node, l, mid, k);
        else res = kth(2 * node + 1, mid, r, k - left);
        st[node] = st[2 * node] + st[2 * node + 1];
        return res;
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> firsteam(n / 2), secondteam(n / 2);
    for (int &e: firsteam) cin >> e;
    for (int &e: secondteam) cin >> e;

    SegmentTree st(n);

    vector<int> t1(n / 2);
    vector<int> t2(n / 2);
    for (int i = 0; i < n / 2; i++) {
        t1[i] = st.kth(1, 0, n, firsteam[i]);
        t2[i] = st.kth(1, 0, n, secondteam[i]);
    }

    for(int e: t1) cout << e << ' ';
    cout << '\n';
    for(int e: t2) cout << e << ' ';
    
    return 0;
}
