// Time  Complexity : O(n)
// Space Complexity : O(n) 

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(n+1 , 0);

        if(n == 0) return 0;

        if(n <= 2) return 1;

        dp[0] = 0;
        dp[1] = dp[2] = 1;

        for(int i = 3 ; i <= n ; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        return dp[n];
    }
};