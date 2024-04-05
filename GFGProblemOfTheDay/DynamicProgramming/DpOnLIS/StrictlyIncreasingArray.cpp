// Time  Complexity : O(n * n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1

class Solution {
  public:

    int min_operations(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> dp(n , 0);
        
        for(int i = 0 ; i < n ; i++) {
            int maxi = 0;
            
            for(int j = 0 ; j < i ; j++) {
                if(nums[i] > nums[j] and (nums[i] - nums[j]) >= i - j) {
                    maxi = max(maxi , dp[j]);
                }
            }
            
            dp[i] = maxi + 1;
        }
        
        int result = n - *max_element(dp.begin() , dp.end());
        
        return result;
    }
};