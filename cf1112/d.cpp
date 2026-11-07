#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef  pair<int,int> pii;
typedef  pair<ll,ll> pll;
typedef  vector<int> vi;

#define all(x) (x).begin(), (x).end()

#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    int n;
    vector<int> bit;

public:
    FenwickTree(int size) {
        this->n = size;
        bit.assign(size + 1, 0);
    }

    void update(int idx, int val) {
        for (; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }

    int count_less_than(int x) {
        if (x <= 1) return 0; 
        return query(x - 1);
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    
    ll t;cin>>t;
    while(t--){
        ll n;cin>>n;
        vll arr(n-1);for(auto &a:arr)cin>>a;
        vll freq(n+1,1);
        vll cant(n+1);
        vll res(n);
        res[0] = arr[0];
        ll act = arr[0];
        bool f= 1;
        ll des =0;
        for (int i = 1; i < n-1; i++)
        {
            if(act<arr[i]){
                res[i] = arr[i];
            }else{

                res[i-1] = arr[i];
            }
        }
        set<ll> st;


        
        

    }

    return 0;
}