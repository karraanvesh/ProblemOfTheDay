// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> nextGreater(n , 0);

        for(int i = 0 ; i < n ; i++) {


            while(!st.empty() and temperatures[i] > temperatures[st.top()]) {
                nextGreater[st.top()] = (i - st.top());
                st.pop();
            }

            st.push(i);
        }

        return nextGreater;
    }
};