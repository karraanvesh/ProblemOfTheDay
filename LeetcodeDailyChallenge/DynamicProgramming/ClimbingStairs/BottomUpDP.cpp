// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);

        dp[0] = 1;

        for(int i = 1 ; i <= n ; i++) {
            int oneStep , twoSteps = 0;

            oneStep = dp[i-1];
            if(i >= 2)
            twoSteps = dp[i-2];

            dp[i] = oneStep + twoSteps;
        }
        return dp[n];
    }
};