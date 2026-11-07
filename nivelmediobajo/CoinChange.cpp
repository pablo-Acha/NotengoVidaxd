#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        if(amount == 0)return 0;
        vector<int> dp(amount+1);
        for (int i = coins.size() - 1; i >= 0; i--)
        {
            if(coins[i]>amount)continue;
            dp[coins[i]] = 1;
            for (int j = coins[i]; j <= amount; j++)
            {
                if(j+coins[i]<= amount && dp[j]){
                    if(dp[j+coins[i]]!=0)dp[j+coins[i]] = min(dp[j+coins[i]],dp[j]+1);
                    else dp[j+coins[i]]= dp[j]+1;
                }
            }
        }
        for(auto a:dp)cout<<a<<" ";
        cout<<"\n";
        if(dp[amount] == 0)return -1;
        return dp[amount];
    }
};