// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum-ii/?envType=daily-question&envId=2024-04-26

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1)
        return *min_element(grid[0].begin() , grid[0].end());

        vector<vector<int>> dp(n , vector<int>(n , 0));

        for(int j = 0 ; j < n ; j++)
        dp[n - 1][j] = grid[n - 1][j];

        for(int i = n - 2 ; i >= 0 ; i--) {

            vector<int> leftMin(n , 0) , rightMin(n , 0);
            leftMin[0] = dp[i+1][0];
            rightMin[n - 1] = dp[i+1][n - 1];

            for(int j = 1 ; j < n ; j++) {
                leftMin[j] = min(leftMin[j - 1] , dp[i+1][j]);
                rightMin[n - j - 1] = min(rightMin[n - j] , dp[i + 1][n - j - 1]);
            }

            for(int j = 0 ; j < n ; j++) {
                int leftInd = j - 1 , rightInd = j + 1;
                int mini = (int) INT_MAX;

                if(leftInd != -1) {
                    mini = min(mini , leftMin[leftInd]);
                }

                if(rightInd != n) {
                    mini = min(mini , rightMin[rightInd]);
                }

                dp[i][j] = grid[i][j] + mini;
            }
        }

        int result = *min_element(dp[0].begin() , dp[0].end());

        return result;
    }
};