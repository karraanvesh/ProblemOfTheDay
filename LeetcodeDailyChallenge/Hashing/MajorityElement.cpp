// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/majority-element/description/?envType=daily-question&envId=2024-02-12

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int , int> mp;

        for(int i = 0 ; i < n ; i++) {
            mp[nums[i]]++;
        }

        map<int,int> :: iterator itr;
        int result = 0;
        
        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            int freq = itr->second;

            if(freq > n/2) {
                result = itr->first;
                break;
            }
        }

        return result;
    }
};