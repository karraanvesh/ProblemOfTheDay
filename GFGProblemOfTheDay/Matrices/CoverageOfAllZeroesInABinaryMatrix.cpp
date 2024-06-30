// Time  Complexity: O(n * m)
// Space Complexity: O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/coverage-of-all-zeros-in-a-binary-matrix4024/1

class Solution {
    private :
    bool isSafe(int i , int j , int n ,int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        int result = 0;
        
        for(int i = 0 ; i < n ; i++) {
            
            for(int j = 0 ; j < m ; j++) {
                
                if(!matrix[i][j]) {
                    
                    int dirRow[] = {-1 , 1 , 0 , 0};
                    int dirCol[] = {0 , 0 , -1 , 1};
                    
                    for(int k = 0 ; k < 4 ; k++) {
                        
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];
                        
                        if(isSafe(newRow , newCol , n , m)) {
                            
                            if(matrix[newRow][newCol])
                            result++;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};