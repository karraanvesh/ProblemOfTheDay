// Time Complexity : O(n * n)
// Space Complexity : O(2 * n ) ~ O(n)

class Solution {
    private:
    bool isSafe(int i , int j , int n) {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<int> ahead(n , 0);


        for(int j = 0 ; j < n ; j++) {
            ahead[j] = matrix[n-1][j];
        }
        
        for(int i = n-2 ; i >= 0 ; i--) {
            vector<int> curr(n , 0);

            for(int j = 0  ; j < n ; j++) {
                int dirRow[] = {1 , 1 , 1 };
                int dirCol[] = {0 , -1 , 1};

                int mini = INT_MAX;

                for(int k = 0 ; k < 3 ; k++) {
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];

                        if(isSafe(newRow , newCol , n)) {
                            int sum = matrix[i][j] + ahead[newCol];
                            mini = min(mini , sum);
                        }
                }

                curr[j] = mini;
            }

            ahead = curr;
        }

        int minSum = INT_MAX;

        for(int i = 0 ; i < n ; i++) {
            int sum = ahead[i];

            minSum = min(minSum , sum);
        }

        return minSum;
    }
};