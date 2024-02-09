// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1 , 0);

        for(int val = 1 ; val <= n ; val++) {
            int mini = INT_MAX;

            for(int i = 1 ; i*i <= val ; i++) {
                int x = dp[val - i*i];
                
                mini = min(mini , 1 + x);
            }

            dp[val] = mini;
        }

        return dp[n];
    }
};