// Time  Complexity : O(n * n * k)
// Space Complexity : O(n * n * k)

// Problem Link : https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

class Solution {
    private :
    bool isSafe(int i , int j , int n) {
        return (i >= 0 and i < n and j >= 0 and j < n);
    }
    long long f(int  i , int j , int k , int n , vector<vector<int>> &arr , vector<vector<vector<long long>>> &dp) {
        
        if(i == n-1 and j == n-1) {
            if(k == arr[i][j]) return 1;
            
            return 0;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        long long totalPaths = 0;
        int dirRow[] = {1 , 0};
        int dirCol[] = {0 , 1};
        
        for(int l = 0 ; l < 2 ; l++) {
            int newRow = i + dirRow[l];
            int newCol = j + dirCol[l];
            
            if(isSafe(newRow , newCol , n) and arr[i][j] <= k) {
                long long noOfPaths = f(newRow , newCol , k - arr[i][j] , n , arr , dp);
                totalPaths += noOfPaths;
            }
        }
        
        return dp[i][j][k] = totalPaths;
    }
public:
    
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        vector<vector<vector<long long>>> dp(n , vector<vector<long long>>(n , vector<long long>(k+1 , -1)));
        
        return f(0 , 0 , k , n , arr , dp);
    }
};