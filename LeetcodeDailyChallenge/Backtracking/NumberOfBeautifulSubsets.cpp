// Time  Complexity : O(2 ^ n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23

class Solution {
    private :
    int result;
    void f(vector<int> &nums , int ind , int k , map<int , int> &mp) {

        if(ind == -1) {
           result++;
           return ;
        }

        if(mp[nums[ind] - k] == 0 and mp[nums[ind] + k] == 0) {
            mp[nums[ind]]++;
            f(nums , ind - 1 , k , mp);
            mp[nums[ind]]--;
        }

        f(nums , ind - 1 , k , mp);

    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        result = 0;

        map<int , int> mp;
        f(nums , n - 1 , k , mp);

        return result - 1;
    }
};