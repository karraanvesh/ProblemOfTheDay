// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03

class Solution {
public:
    int minDifference(vector<int>& nums) {
      int n = nums.size();
        
        if(n <= 4) return 0;
        
        sort(nums.begin() , nums.end());
        
        int result = INT_MAX;
        int k = 3;
        
        for(int i = 0 ; i <= k ; i++) {
            int minEle = nums[i];
            int maxEle = nums[n - ((k + 1) - i)];
            
            int diff = maxEle - minEle;
            
            result = min(result , diff);
        }
        
        for(int i = n-4 ; i < n ; i++) {
            int minEle = nums[0];
            int maxEle = nums[i];
            
            int diff = maxEle - minEle;
            
            result = min(result , diff);
        }
        
        return result;
        
    }
};