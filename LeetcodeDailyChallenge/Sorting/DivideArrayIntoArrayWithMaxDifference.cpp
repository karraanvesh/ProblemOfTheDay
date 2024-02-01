// Time Complexity  : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2024-02-01

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> result;

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < n ; i += 3) {

            int lastElementInPartition = nums[i + 2];
            int diff = lastElementInPartition - nums[i];

            if(diff <= k) {
                vector<int> currPartition;

                for(int j = i ; j < i + 3; j ++)
                currPartition.push_back(nums[j]);

                result.push_back(currPartition);
            } else {
                vector<vector<int>> brr;
                return brr;
            }
        }

        return result;
    }
};