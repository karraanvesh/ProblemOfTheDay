// Time  Complexity : O(n * m)
// Space Complexity : O(n * m) + O(n + m) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/paths-to-reach-origin3850/1

class Solution
{
    private :
    int mod = 1e9 + 7;
    int numberOfPaths(int i , int j , int destx , int desty , int n , int m , vector<vector<int>> &dp) {
        
        if(i < 0 or i >= n or j < 0 or j >= m) return 0;
        
        if(i == destx and j == desty)
        return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int a = numberOfPaths(i , j + 1 , destx , desty , n , m , dp);
        int b = numberOfPaths(i + 1 , j , destx , desty , n , m , dp);
        
        return dp[i][j] = (a%mod + b%mod)%mod;
    }
public:
    int ways(int x, int y)
    {
        int n = x + 1;
        int m = y + 1;
        
        vector<vector<int>> dp(n , vector<int>(m , -1));
        
        return numberOfPaths(0 , 0 , x , y , n , m , dp);
    }
};