// Time  Complexity : O(n * m)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/maximum-sum-of-hour-glass3842/1

class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        
        int maxSum = -1;
        
        for(int i = 0 ; i < n - 2 ; i++) {
            
            for(int j = 0 ; j < m - 2 ; j++) {
                int starti  = i , startj = j;
                int endi = starti + 2 , endj = startj + 2;
                
                int sum = mat[i][j] + mat[i][j+1] + mat[i][j+2];
                sum += mat[i+1][j+1];
                sum += mat[i+2][j] + mat[i+2][j+1] + mat[i+2][j+2];
                
                maxSum = max(maxSum , sum);
            }
        }
        
        return maxSum;
    }
};