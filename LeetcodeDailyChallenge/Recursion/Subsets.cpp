// Time  Complexity : O(2 ^ n)
// Space Complexity : O(2 ^ n)

// Problem Link : https://leetcode.com/problems/subsets/?envType=daily-question&envId=2024-05-21

class Solution {
    private :
    void f(vector<int> &nums , int ind , vector<vector<int>> &result , vector<int> &v) {

        if(ind == -1) {
            result.push_back(v);
            return ;
        }

        v.push_back(nums[ind]);

        f(nums , ind - 1 , result , v);

        v.pop_back();

        f(nums , ind - 1 , result , v);

        return ;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> result;
        vector<int> v;

        f(nums , n - 1 , result , v);

        return result;
    }
};