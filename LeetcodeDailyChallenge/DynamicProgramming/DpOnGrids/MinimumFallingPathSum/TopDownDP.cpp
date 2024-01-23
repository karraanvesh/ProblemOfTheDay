// Time Complexity : O(n * n)
// Space Complexity : O(n * n) + O(n) (auxilaru stack space)

// Problem Link : https://leetcode.com/problems/minimum-falling-path-sum/?envType=daily-question&envId=2024-01-19

class Solution {
    private:
    bool isSafe(int i , int j , int n) {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }
    int f(int i , int j , vector<vector<int>> &matrix , int n , vector<vector<long>> &dp) {
        if(i == n-1) {
            return matrix[i][j];
        }

        if(dp[i][j] != -1)
        return dp[i][j];

        int dirRow[] = {1 , 1 , 1 };
        int dirCol[] = {0 , -1 , 1};

        int mini = INT_MAX;

        for(int k = 0 ; k < 3 ; k++) {
            int newRow = i + dirRow[k];
            int newCol = j + dirCol[k];

            if(isSafe(newRow , newCol , n)) {
                int sum = matrix[i][j] + f(newRow , newCol , matrix , n , dp);
                mini = min(mini , sum);
            }
        }

        return dp[i][j] = mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<long>> dp(n , vector<long>(n , -1));
        int minSum = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            int sum = f(0 , i , matrix , n , dp);

            minSum = min(minSum , sum);
        }

        return minSum;
    }
};