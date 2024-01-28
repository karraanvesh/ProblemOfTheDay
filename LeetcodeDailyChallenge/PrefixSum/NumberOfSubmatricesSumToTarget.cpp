// Time Complexity  : O(n * m * n * m)
// Space Complexity : O(n * m)

// Problem Link : https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<long>> prefixSum(n , vector<long>(m , 0));
        prefixSum[0][0] = matrix[0][0];

        for(int j = 1 ; j < m ; j++) {
            prefixSum[0][j] = prefixSum[0][j-1] + matrix[0][j];
        }

        for(int i = 1 ; i < n ; i++) {
            prefixSum[i][0] = prefixSum[i-1][0] + matrix[i][0];
        }

        for(int i = 1 ; i < n ; i++) {

            for(int j = 1 ; j < m ; j++) {

                prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + matrix[i][j];
            }
        }

        int noOfSubmatrices = 0;

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                for(int k = i ; k < n ; k++) {

                    for(int l = j ; l < m ; l++) {
                        // start cell (i , j) , end cell (k , l)

                        int submatrixSum = prefixSum[k][l];

                        if(i == 0 and j != 0) {
                            submatrixSum = submatrixSum - prefixSum[k][j-1];
                        }

                        else if(j == 0 and i != 0) {
                            submatrixSum = submatrixSum - prefixSum[i-1][l];
                        }

                        else if(i != 0 and j != 0) {
                            submatrixSum = submatrixSum - prefixSum[k][j-1] - prefixSum[i-1][l] + prefixSum[i-1][j-1];
                        }

                        target = target;

                        if(submatrixSum == target) {
                            noOfSubmatrices++;
                        }
                    }
                }
            }
        }

        return noOfSubmatrices;
    }
};