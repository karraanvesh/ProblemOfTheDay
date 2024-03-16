// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;

        int sum , maxLen;
        sum = maxLen = 0;

        mp.insert({0 , -1});

        for(int i = 0 ; i < n ; i++) {
            sum += (nums[i] == 0) ? -1 : 1;

            if(mp.find(sum) != mp.end()) {
                int lenOfSubarray = i - mp[sum];
                maxLen = max(maxLen , lenOfSubarray);
            }

            else {
                mp.insert({sum , i});
            }
        }

        return maxLen;
    }
};