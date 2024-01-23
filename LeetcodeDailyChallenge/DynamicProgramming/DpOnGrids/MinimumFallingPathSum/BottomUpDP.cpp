// Time Complexity : O(n * n)
// Space Complexity : O(n * n)

class Solution {
    private:
    bool isSafe(int i , int j , int n) {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<long>> dp(n , vector<long>(n , -1));

        for(int j = 0 ; j < n ; j++) {
            dp[n-1][j] = matrix[n-1][j];
        }
        
        for(int i = n-2 ; i >= 0 ; i--) {

            for(int j = 0  ; j < n ; j++) {
                int dirRow[] = {1 , 1 , 1 };
                int dirCol[] = {0 , -1 , 1};

                int mini = INT_MAX;

                for(int k = 0 ; k < 3 ; k++) {
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];

                        if(isSafe(newRow , newCol , n)) {
                            int sum = matrix[i][j] + dp[newRow][newCol];
                            mini = min(mini , sum);
                        }
                }

                dp[i][j] = mini;
            }
        }

        int minSum = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            int sum = dp[0][i];

            minSum = min(minSum , sum);
        }

        return minSum;
    }
};