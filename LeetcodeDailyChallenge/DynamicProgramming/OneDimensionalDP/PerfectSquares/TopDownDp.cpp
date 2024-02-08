// Time  Complexity : O(n * logn)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/perfect-squares/description/?envType=daily-question&envId=2024-02-08

class Solution {
    private :
    int f(int n , vector<int> &dp) {

        if(n == 0 ) return 0;

        if(dp[n] != -2) return dp[n];

        int mini = INT_MAX;

        for(int i = 1 ; i*i <= n ; i++) {
            int x = f(n - i*i , dp);
            
            mini = min(mini , 1 + x);
        }

        return dp[n] = (mini == INT_MAX) ? -1 : mini;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n+1 , -2);

        return f(n , dp);
    }
};