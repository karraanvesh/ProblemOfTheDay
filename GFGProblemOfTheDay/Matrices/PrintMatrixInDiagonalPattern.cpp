// Time  Complexity : O(n * n)
// Space Complexity : O(n * n)

// Problem Link : https://www.geeksforgeeks.org/problems/print-matrix-in-diagonal-pattern/1

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
        int n = mat.size();
        vector<vector<int>> result;
        bool flag = true;
        
        for(int col = 0 ; col < n ; col++) {
            int row = 0;
            int temp = col;
            
            vector<int> pattern;
            while(temp >= 0) {
                pattern.push_back(mat[row][temp]);
                temp--;
                row++;
            }
            
            if(flag)
            reverse(pattern.begin() , pattern.end()); 
            
            result.push_back(pattern);
            
            flag = !flag;
        }
        
        for(int row = 1 ; row < n ; row++) {
            
            int currRow = row , currCol = n - 1 ;
            vector<int> pattern;
            
            while(currRow < n) {
                pattern.push_back(mat[currRow][currCol]);
                currRow++;
                currCol--;
            }
            
            if(flag)
            reverse(pattern.begin() , pattern.end());
            
            result.push_back(pattern);
            
            flag = !flag;
        }
        
        vector<int> finalPattern;
        int m = result.size();
        
        for(int i = 0 ; i < m ; i++) {
            int noOfCols = result[i].size();
            
            for(int j = 0 ; j < noOfCols ; j++) {
                finalPattern.push_back(result[i][j]);
            }
        }
        
        return finalPattern;
        
    }
};