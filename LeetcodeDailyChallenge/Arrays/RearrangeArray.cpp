// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positives , negatives;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] >= 0) {
                positives.push_back(nums[i]);
            } else {
                negatives.push_back(nums[i]);
            }
        }

        vector<int> result;

        for(int i = 0 ; i < n / 2 ; i++) {
            result.push_back(positives[i]);
            result.push_back(negatives[i]);
        }

        return result;
    }
};