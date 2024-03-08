// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/count-elements-with-maximum-frequency/?envType=daily-question&envId=2024-03-08

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;
        int maxFreq = 0;

        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
            int currFreq = mp[nums[i]];

            maxFreq = max(maxFreq , currFreq);
        }

        map<int , int> :: iterator itr;
        int result = 0;

        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            int freq =  itr->second;

            if(freq == maxFreq)
            result += freq;
        }

        return result;
    }
};