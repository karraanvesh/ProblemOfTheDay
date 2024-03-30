// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/?envType=daily-question&envId=2024-03-30

class Solution {   
    private :
    long long noOfSubarrays(vector<int> &nums , int n , int k) {
        long long left , right , uniqueCount , totalSubarrays;
        left = right = uniqueCount = totalSubarrays = 0;

        map<int , int> mp;

        while(right < n) {
            int currEle = nums[right];
            mp[currEle]++;

            if(mp[currEle] == 1)
            uniqueCount++;

            if(uniqueCount >= k) {

                int len = n - right , ct = 1;
                int prevEle = nums[left];
                mp[prevEle]--;

                if(mp[prevEle] == 0)
                uniqueCount--;

                while(left <= right and uniqueCount >= k) {
                    left++;
                    ct++;
                    prevEle = nums[left];
                    mp[prevEle]--;

                    if(mp[prevEle] == 0)
                    uniqueCount--;
                }

                left++;

                totalSubarrays += (len * ct);
            }
            right++;
        }

        return totalSubarrays;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();

        long long eq1 = noOfSubarrays(nums , n , k);
        long long eq2 = noOfSubarrays(nums , n , k + 1);

        long long result = eq1 - eq2;

        return result;
    }
};