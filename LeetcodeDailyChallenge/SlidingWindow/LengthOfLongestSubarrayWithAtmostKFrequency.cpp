// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/?envType=daily-question&envId=2024-03-28

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int left , right , maxFreq , maxLen;
        left = right = maxFreq = maxLen = 0;

        map<int , int> mp;

        while(right < n) {
            int currEle = nums[right];
            
            mp[currEle]++;

            maxFreq = max(maxFreq , mp[currEle]);

            if(maxFreq > k) {
                int len = right - left;

                maxLen = max(maxLen , len);
                int prevEle = nums[left];

                while(left <= right and mp[currEle] > k) {
                    mp[prevEle]--;
                    left++;
                    prevEle = nums[left];
                }
            }

            right++;
        }

        int len = right - left;
        maxLen = max(maxLen , len);

        return maxLen;
    }
};