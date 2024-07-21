// Time  Complexity : O(n * m)
// Space Complexity : O(n + m)

// Problem Link : https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/description/?envType=daily-question&envId=2024-07-20

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();

        vector<int> tempRow , tempCol;
        tempRow = rowSum;
        tempCol = colSum;

        int i , j;
        i = j = 0;

        vector<vector<int>> matrix(n , vector<int>(m , 0));

        while(i < n and j < m) {

            int ele = min(tempRow[i] , tempCol[j]);

            matrix[i][j] = ele;

            tempRow[i] -= ele;
            tempCol[j] -= ele;

            i++;
            j++;
        }

        i = j = 0;

        while(i < n and j < m) {

            int diff = tempRow[i] + tempCol[j];

            if(diff == tempRow[i]) {
            	
                for(int col = j+1 ; col < m ; col++) {
                	
                    matrix[i][col] = min(diff , tempCol[col]);

                    diff -= matrix[i][col];

                    tempCol[col] -= matrix[i][col];
                    tempRow[i] -= matrix[i][col];
                }
            }

            else if(diff == tempCol[j]) {

                for(int row = i+1; row < n ; row++) {

                    matrix[row][j] = min(diff , tempRow[row]);

                    diff -= matrix[row][j];

                    tempRow[row] -= matrix[row][j];
                    tempCol[j] -= matrix[row][j];
                }
            }

            i++;
            j++;
        }

        return matrix;
    }
};
