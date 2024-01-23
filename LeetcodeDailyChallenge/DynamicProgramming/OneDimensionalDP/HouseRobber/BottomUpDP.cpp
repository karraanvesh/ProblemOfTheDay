// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[n-1] , nums[n-2]);

        vector<int> dp(n , 0);

        dp[0] = nums[0];
        dp[1] = max(nums[0] , nums[1]);

        for(int ind = 2 ; ind < n ; ind++) {
            int loot = nums[ind] + dp[ind - 2];
            int dontLoot = dp[ind - 1];

            dp[ind] = max(loot , dontLoot);
        }

        return dp[n-1];
    }
};