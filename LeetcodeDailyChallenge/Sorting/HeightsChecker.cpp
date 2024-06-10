// Time  Complexity : O(n * logn)
// Space Complexity: O(n)

// Problem Link : https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10

class Solution {
public:
    int heightChecker(vector<int>& heights) {
       int n = heights.size();
        
        vector<int> arr = heights;
        sort(arr.begin() , arr.end());
        int result = 0;
        
        for(int i = 0 ; i < n ; i++)    {
            if(heights[i] != arr[i])
                result++;
        }
        
        return result;
    }
};