// Time Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/first-missing-positive/?envType=daily-question&envId=2024-03-26

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        set<int> st;

        for(int i = 0 ; i < n ; i++) {
            if(nums[i] > 0)
            st.insert(nums[i]);
        }

        if(st.size() == 0) return 1;

        set<int> :: iterator itr;
        itr = st.begin();

        if(*itr > 1) return 1;

        int prev = *itr;

        itr++;

        while(itr != st.end()) {
            int curr = *itr;

            if(curr != prev + 1)
            return prev + 1;

            prev = curr;

            itr++;
        }

        return prev + 1;
    }
};