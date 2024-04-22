// Time  Complexity : O(n * m)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1

class Solution {
  public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int result = 0 , minOnes = INT_MAX;
        
        for(int i = 0 ; i < n ; i++) {
            
            int ct = 0;
            for(int j = 0 ; j < m ; j++) {
                
                if(a[i][j])
                ct++;
            }
            
            if(ct < minOnes) {
                minOnes = ct;
                result = i + 1;
            }
        }
        
        return result;
    }
};