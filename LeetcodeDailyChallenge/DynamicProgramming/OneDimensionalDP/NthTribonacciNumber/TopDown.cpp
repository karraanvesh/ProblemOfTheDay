// Time  Complexity : O(n)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/n-th-tribonacci-number/description/?envType=daily-question&envId=2024-04-24

class Solution {
    private :
    int f(int n , vector<int> &dp) {
        if(n == 0) return 0;

        if(n <= 2) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = f(n - 1 , dp) + f(n - 2 , dp) + f(n - 3 , dp);
    }
public:
    int tribonacci(int n) {
        vector<int> dp(n+1 , -1);
        return f(n , dp);
    }
};