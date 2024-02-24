// Time  Complexity : O(n)
// Space Complexity : O(n) + O(n / 2) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/maximum-sum-problem2211/1

class Solution
{
    private :
    int f(int n , vector<int> &dp) {
        
        if(n <= 1) return n;
        
        if(dp[n] != -1)
        return dp[n];
        
        int sum = 0;
        
        sum += f(n / 2 , dp);
        
        sum += f(n / 3 , dp);
        
        sum += f(n / 4 , dp);
        
        return dp[n] = max(n , sum);
    }
    public:
    int maxSum(int n)
    {
        vector<int> dp(n+1 , -1);
        
        if(n == 0) return 0;
        
        return f(n , dp);
    }
};