// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2024-03-29

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int maxEle = *max_element(nums.begin() , nums.end());

        map<int , int> mp;
        int left , right;
        long long result;

        left = right = result = 0;

        while(right < n) {
            int currEle = nums[right];

            mp[currEle]++;

            if(currEle == maxEle and mp[currEle] >= k) {

                long long len = n - right , ct = 1;
                int prevEle = nums[left];
                mp[prevEle]--;

                while(left <= right and mp[currEle] >= k) {
                    ct++;
                    left++;
                    prevEle = nums[left];
                    mp[prevEle]--;
                }

                left++;

                result += (len * ct);
            }

            right++;
        }

        return result;
    }
};