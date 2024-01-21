// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        if(n == 2) return max(nums[n-1] , nums[n-2]);

        int prev1 , prev2;
        prev1 = max(nums[1] , nums[0]);
        prev2 = nums[0];

        for(int ind = 2 ; ind < n ; ind++) {
            int loot = nums[ind] + prev2;
            int dontLoot = prev1;

            int curr = max(loot , dontLoot);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};