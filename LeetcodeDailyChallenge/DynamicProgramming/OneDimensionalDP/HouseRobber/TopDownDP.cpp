// Time Complexity : O(n)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21

class Solution {
    private:
    int maxLoot(vector<int> &nums , int ind , vector<int> &dp) {

        if(ind == 0) {
            return nums[ind];
        }

        if(ind == 1) {
            return max(nums[ind] , nums[ind-1]);
        }

        if(dp[ind] != -1) return dp[ind];

        int loot = nums[ind] + maxLoot(nums , ind - 2 , dp);
        int dontLoot = maxLoot(nums , ind - 1 , dp);

        return dp[ind] = max(loot , dontLoot);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n , -1);

        return maxLoot(nums , n-1 , dp);
    }
};