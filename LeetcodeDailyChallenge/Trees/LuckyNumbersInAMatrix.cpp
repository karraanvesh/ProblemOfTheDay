// Time Complexity: O(n * (m*logn) + m * (n*logm))
// Space Complexity: O(min(n , m))

// Problem Link : https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        set<pair<int , int>> st;
        
        for(int i = 0 ; i < n ; i++) {
        	
            int mini = matrix[i][0] , col = 0;
            
            for(int j = 0 ; j < m ; j++) {
            	
               if(matrix[i][j] < mini) {
                   mini = matrix[i][j];
                   col = j;
               }
            }
            
            st.insert({mini , col});
        }
        
        vector<int> result;
        
        for(int j = 0 ; j < m ; j++) {
        	
            int maxi = matrix[0][j] , col = j;
            
            for(int i = 0 ; i < n ; i++) {
            	
                if(matrix[i][j] > maxi) {
                    maxi = matrix[i][j];
                }
            }
            
            if(st.count({maxi , j})) {
                result.push_back(maxi);
            }
        }
        
        return result;
    }
};
