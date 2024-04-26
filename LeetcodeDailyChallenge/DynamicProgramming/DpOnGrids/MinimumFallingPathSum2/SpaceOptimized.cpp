// Time  Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();

        if(n == 1)
        return *min_element(grid[0].begin() , grid[0].end());

        vector<int> ahead(n , 0);

        for(int j = 0 ; j < n ; j++)
        ahead[j] = grid[n - 1][j];

        for(int i = n - 2 ; i >= 0 ; i--) {

            vector<int> leftMin(n , 0) , rightMin(n , 0);
            leftMin[0] = ahead[0];
            rightMin[n - 1] = ahead[n - 1];

            for(int j = 1 ; j < n ; j++) {
                leftMin[j] = min(leftMin[j - 1] , ahead[j]);
                rightMin[n - j - 1] = min(rightMin[n - j] , ahead[n - j - 1]);
            }

            vector<int> curr(n , 0);

            for(int j = 0 ; j < n ; j++) {
                int leftInd = j - 1 , rightInd = j + 1;
                int mini = (int) INT_MAX;

                if(leftInd != -1) {
                    mini = min(mini , leftMin[leftInd]);
                }

                if(rightInd != n) {
                    mini = min(mini , rightMin[rightInd]);
                }

                curr[j] = grid[i][j] + mini;
            }

            ahead = curr;
        }

        int result = *min_element(ahead.begin() , ahead.end());

        return result;
    }
};