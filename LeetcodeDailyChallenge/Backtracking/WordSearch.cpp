// Time  Complexity : O(n * m * n * m)
// Space Complexity : O(n * m)

// Problem Link : https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }

    bool findWord(vector<vector<char>> &board , int rows , int cols , string word , 
    int row , int col , int ind , int n , vector<vector<bool>> &visited) {

        if(ind == n) {
            return true;
        }

        visited[row][col] = true;

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        for(int k = 0 ; k < 4 ; k++) {
            int newRow = row + dirRow[k];
            int newCol = col + dirCol[k];

            if(isSafe(newRow , newCol , rows , cols) and !visited[newRow][newCol] and word[ind] == board[newRow][newCol]) {

                if(findWord(board , rows , cols , word , newRow , newCol , ind + 1 , n , visited))
                return true;
            }
        }

        visited[row][col] = false; 

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        int len = word.size();
        vector<vector<bool>> visited(rows , vector<bool>(cols , false));

        for(int i = 0 ; i < rows ; i++) {

            for(int j = 0 ; j < cols ; j++) {
                char ch = board[i][j];

                if(ch == word[0]) {
                    
                    if(findWord(board , rows , cols , word , i , j , 1 , len , visited)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};