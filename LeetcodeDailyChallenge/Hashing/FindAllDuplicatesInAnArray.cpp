// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/?envType=daily-question&envId=2024-03-25

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;

        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }

        map<int , int> :: iterator itr;
        vector<int> result;

        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            int freq = itr->second;

            if(freq == 2) {
                result.push_back(itr->first);
            }
        }

        return result;

    }
};