// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/count-subarrays-with-fixed-bounds/?envType=daily-question&envId=2024-03-31

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long res = 0;
        bool minFound = false, maxFound = false;
        int start = 0, minStart = 0, maxStart = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num < minK || num > maxK) {
                minFound = false;
                maxFound = false;
                start = i+1;
            }
            if (num == minK) {
                minFound = true;
                minStart = i;
            }
            if (num == maxK) {
                maxFound = true;
                maxStart = i;
            }
            if (minFound && maxFound) {
                int x = (min(minStart, maxStart) - start + 1);

                res += x;
            }
        }
        return res;
    }
};