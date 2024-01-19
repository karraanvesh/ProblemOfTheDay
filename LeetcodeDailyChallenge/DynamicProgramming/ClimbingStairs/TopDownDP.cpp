// Time Complexity : O(n)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

class Solution {
    private :
    int noOfWays(int n , vector<int> &dp) {

        if(n == 0) return 1;

        if(dp[n] != -1) return dp[n];

        int oneStep , twoSteps = 0;

        oneStep = noOfWays(n-1 , dp);
        if(n >= 2)
        twoSteps = noOfWays(n-2 , dp);

        return dp[n] = oneStep + twoSteps;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);

        return noOfWays(n , dp);
    }
};