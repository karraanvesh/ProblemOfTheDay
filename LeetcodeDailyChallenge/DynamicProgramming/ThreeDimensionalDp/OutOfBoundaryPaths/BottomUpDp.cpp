// Time Complexity : O(n * m * maxMoves)
// Space Complexity : O(2 * n * m) ~ O(n * m)
// where n and m are the rows and columns 

class Solution {
public:
    int findPaths(int m, int n, int maxMoves, int startRow, int startCol) {
        
        swap(n , m);

        n += 2;
        m += 2;

        vector<vector<int>> prevMatrix(n+2 , vector<int>(m+2 , 0));

        for(int moves = 0 ; moves <= maxMoves ; moves++) {

            for(int i = 0 ; i < n ; i++) {

                for(int j = 0 ; j < m ; j++) {

                    if(i == 0 or j == 0 or i == n-1 or j == m-1)
                    prevMatrix[i][j] = 1;
                }

            }
        }

        startRow++;
        startCol++;

        long mod = 1e9 + 7;

        for(int moves = 1 ; moves <= maxMoves ; moves++) {
            vector<vector<int>> currMatrix(n+2 , vector<int>(m+2 , 1));
            for(int i = 1 ; i < n-1 ; i++) {

                for(int j = 1 ; j < m-1 ; j++) {

                        int dirRow[] = {-1 , 1 , 0 , 0};
                        int dirCol[] = {0 , 0 , -1 , 1};

                        long result = 0;

                        for(int k = 0 ; k < 4 ; k++) {

                            int newRow = i + dirRow[k];
                            int newCol = j + dirCol[k];

                            long x = prevMatrix[newRow][newCol];
                            result = (result%mod + x%mod)%mod;
                        }

                        currMatrix[i][j] = result;
                }
            }

            prevMatrix = currMatrix;
        }

        return (int)prevMatrix[startRow][startCol];
    }
};