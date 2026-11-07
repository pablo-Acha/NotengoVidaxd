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
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int ini = 0;
        int mx = 0;
        if(s.size() == 0)return 0;
        for (int i = 0; i < s.size(); i++)
        {
            if(!(mp.find(s[i]) == mp.end()) && !(mp[s[i]] < ini)){
                ini = i+1;
            }
            mx = max(i-ini+1,mx);
        }
        
        return mx;                 
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;

    return 0;   
}