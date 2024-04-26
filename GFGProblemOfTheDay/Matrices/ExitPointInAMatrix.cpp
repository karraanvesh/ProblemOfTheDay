// Time  Complexity : O(n * m)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/exit-point-in-a-matrix0905/1

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        int i , j , exitRow , exitCol;
        i = j = 0;
        
        string dir = "right";
        
        while(true) {
            exitRow = i;
            exitCol = j;
            
            if(mat[i][j]) {
                mat[i][j] = 0;
                
                if(dir.compare("right") == 0) {
                    dir = "down";
                    i++;
                }
                
                else if(dir.compare("down") == 0) {
                    dir = "left";
                    j--;
                }
                
                else if(dir.compare("left") == 0) {
                    dir = "up";
                    i--;
                }
                
                else {
                    dir = "right";
                    j++;
                }
            }
            
            else {
                if(dir.compare("right") == 0) {
                   j++;
                }
                
                else if(dir.compare("down") == 0) {
                    i++;
                }
                
                else if(dir.compare("left") == 0) {
                    j--;
                }
                
                else {
                    i--;
                }
            }
            
            dir = dir;
            
            if(!isSafe(i , j , n , m))
            break;
        }
        
        vector<int> result;
        result.push_back(exitRow);
        result.push_back(exitCol);
        
        return result;
    }
};