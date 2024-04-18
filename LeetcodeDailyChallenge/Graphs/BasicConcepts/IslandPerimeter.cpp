// Time  Complexity : O(n * m)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/island-perimeter/?envType=daily-question&envId=2024-04-18

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                int ct = 0;
                if(grid[i][j] == 1) {

                    int dirRow[] = {-1 , 1 , 0 , 0};
                    int dirCol[] = {0 , 0 , -1 , 1};

                    for(int k = 0 ; k < 4 ; k++) {
                        int newRow = i + dirRow[k];
                        int newCol = j + dirCol[k];

                        if(!isSafe(newRow , newCol , n , m)) {
                            ct++;
                            continue;
                        }

                        if(grid[newRow][newCol] == 0)
                        ct++;
                    }
                }

                result += ct;
            }
        }

        return result;
    }
};