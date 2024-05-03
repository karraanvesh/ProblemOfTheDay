// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/?envType=daily-question&envId=2024-05-02

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int , int> mp;

        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }

        int maxi = -1;

        for(int i = 0 ; i < n ; i++) {

            if(nums[i] > 0) {
                int ele = (nums[i] * -1);

                if(mp.find(ele) != mp.end())
                maxi = max(maxi , nums[i]);
            }
        }

        return maxi;
    }
};