#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;

ll gaus(ll n){
    return (n*(n+1))/2;
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        multimap<int,int> mp;
        int n= temperatures.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++)
        {
            auto p = mp.lower_bound(temperatures[i]);
            if(p != mp.begin()){
                for (auto it = prev(p); ; it = prev(it)) {
                    auto &[val, inx] = *it;
                    res[inx] = i - inx;
                    if (it == mp.begin()) break;
                }
                for (auto it = mp.begin(); it != p; ) {
                    it = mp.erase(it);
                }
            }
            mp.emplace(temperatures[i],i);
        }
        return res; 
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
}