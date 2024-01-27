// Time Complexity  : O(n * k)
// Space Complexity : O(n * k) + O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27

class Solution {
    private :
    int mod = 1e9 + 7;

    int f(int s , int n , int k , vector<vector<int>> &dp) {

        if(s == n-1) {

            if(k == 0) return 1;

            return 0;
        }

        if(dp[s][k] != -1) return dp[s][k];

        int result = 0;

        for(int i = s ; i < n ; i++) {
        
            int diff = i - s;

            if(diff <= k) {
                int reversePairCount = f(s+1 , n , k - diff , dp);

                result = (result%mod + reversePairCount%mod)%mod;  
            }
        }

        return dp[s][k] = result;
    }
public:
    int kInversePairs(int n, int k) {

        vector<vector<int>> dp(n , vector<int>(k+1 , -1));

        return f(0 , n , k , dp);
    }
};