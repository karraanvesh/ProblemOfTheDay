// Time  Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
    public:
    int maxSum(int n)
    {
        vector<int> dp(n+1 , -1);
        
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        dp[4] = 4;
        
        for(int i = 5 ; i <= n ; i++) {
            
            dp[i] = max(i , dp[i / 2] + dp[i / 3] + dp[i / 4]);
        }
        
        return dp[n];
    }
};