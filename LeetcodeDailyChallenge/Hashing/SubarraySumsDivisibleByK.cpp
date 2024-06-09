// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/subarray-sums-divisible-by-k/description/?envType=daily-question&envId=2024-06-09

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
      int n = nums.size();
      long sum , result;
        sum = result = 0;
        map<long , long> mp;
        
        mp.insert({0 , 1});
        
        for(int i = 0 ; i < n ; i++)    {

            sum = (sum + nums[i]%k + k)%k;  
            
            if(mp.find(sum) != mp.end()) {
                result += mp[sum];
                mp[sum]++;
            }
            
            else
            mp.insert({sum , 1});
        }
        
        return result;
    }
};