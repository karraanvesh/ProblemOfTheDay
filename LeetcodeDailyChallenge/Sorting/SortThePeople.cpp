// Time  Complexity: O(n * logn)
// Space Complexity: O(2 * n) ~ O(n)

// Problem Link : https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n = names.size();
        vector<pair<int , string>> arr;
        
        for(int i = 0 ; i < n ; i++) {
            int ht = heights[i];
            string name = names[i];
            
            arr.push_back({ht , name});
        }
        
        sort(arr.begin() , arr.end() , greater<pair<int , string>>());
        
        vector<string> result;
        
        for(int i = 0 ; i < n ; i++) {
            result.push_back(arr[i].second);
        }
        
        return result;
    }
};
