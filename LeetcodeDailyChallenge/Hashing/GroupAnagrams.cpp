// Time Complexity : O(n*logn)
// Space Complexity : O(n) 

// Problem Link : https://leetcode.com/problems/group-anagrams/description/?envType=daily-question&envId=2024-02-06

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        map<string , vector<string>> mp;

        for(int i = 0 ; i < n ; i++) {
           
            string sortedStr = strs[i];
            sort(sortedStr.begin() , sortedStr.end());

            mp[sortedStr].push_back(strs[i]);
        }

        map<string , vector<string>> :: iterator itr;
        vector<vector<string>> result;

        for(itr = mp.begin() ; itr !=  mp.end() ; itr++) {
            vector<string> vect = itr->second;
            int m = vect.size();
            vector<string> group;

            for(int i = 0 ; i < m ; i++) {
                group.push_back(vect[i]);
            }

            result.push_back(group);
        }

        return result;
    }
};