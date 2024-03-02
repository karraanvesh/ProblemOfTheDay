// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/squares-of-a-sorted-array/description/?envType=daily-question&envId=2024-03-02

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for(int i = 0 ; i < n ; i++) {
            int ele = (nums[i] * nums[i]);
            result.push_back(ele);
        }

        sort(result.begin() , result.end());

        return result;
    }
};