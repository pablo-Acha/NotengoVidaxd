#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
const ll MOD = 1e9+7;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)return 0;
        int n = prices.size();
        vector<int> vi(n);
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            if(prices[i]>prices[i-1]){
                int ini = i-1;
                while(i<n && prices[i]>prices[i-1]){
                    i++;
                }
                sum += prices[i-1]-prices[ini];
                vi[ini]= 1;
                vi[i-1]= 2;
                i--;
            }
        }
        for(auto a:vi)cout<<a<<" ";
        cout<<"\n";
        cout<<sum<<"\n";
        for (int i = 2; i < n; i++)
        {
            if(vi[i] == 1 && vi[i-1] == 2){
                
            }
        }
        return sum;
        
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution* a = new Solution();
    vector<int> arr = {2,6,8,7,8,7,9,4,1,2,4,5,8};
    cout<<a->maxProfit(arr)<<"\n";
    return 0;   
}