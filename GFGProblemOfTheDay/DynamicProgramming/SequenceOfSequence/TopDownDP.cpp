// Time Complexity : O(n * m)
// Space Complexity : O(n * m) + O(logn) (auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

class Solution{
    private:
    int f(int n , int m , int prev , vector<vector<int>> &dp) {
        
        if(n == 0) return 1;
        
        if(dp[n][prev] != -1) return dp[n][prev];
        
        int seqCount = 0;
        
        int start = (prev == 0) ? 1 : 2*prev;
        
        for(int i = start ; i <= m ; i++) {
            
            int x = f(n-1 , m , i , dp);
            seqCount += x;
        }
        
        return dp[n][prev] = seqCount;
    }
public:
    int numberSequence(int m, int n){
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
        
        return f(n , m , 0 , dp);
    }
};