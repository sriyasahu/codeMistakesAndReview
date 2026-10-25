#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long long>> dp(n+1,vector<long long> (amount+1));
        int i,j;
        //int MOD=1e9+7;
        //1st col all 1
        for(i=0;i<=n;i++){
            dp[i][0]=1;
        }
        //1st row all 0 leave 1st col
        for(j=1;j<=amount;j++){
            dp[0][j]=0;
        }

        for(i=1;i<=n;i++){
            for(j=1;j<=amount;j++){
                long long nottake=dp[i-1][j];
                long long take=0;
                if(coins[i-1]<=j)
                take+=dp[i][j-coins[i-1]];
                dp[i][j]=take+nottake;
            }
        }
        return (int) dp[n][amount];
    }
};