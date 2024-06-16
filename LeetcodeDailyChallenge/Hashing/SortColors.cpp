// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2024-06-12

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zc , oc , tc;
        zc = oc = tc = 0;

        int n = nums.size();

        for(int i = 0 ; i < n ; i++) {

            if(nums[i] == 0)
            zc++;

            else if(nums[i] == 1)
            oc++;

            else
            tc++;
        }

        int ind = 0;

        while(zc--) {
            nums[ind] = 0;
            ind++;
        }

        while(oc--) {
            nums[ind] = 1;
            ind++;
        }

        while(tc--) {
            nums[ind] = 2;
            ind++;
        }

        return ;
    }
};