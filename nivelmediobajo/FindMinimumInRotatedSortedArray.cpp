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
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1; 
        int mid;
        while(l<r){
            mid = (l+r) /2;
            if(mid < nums[l]){
                r = mid;
            }else{
                l = mid +1;
            }
        }  
        return nums[l];   
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;cin>>n;

    return 0;   
}