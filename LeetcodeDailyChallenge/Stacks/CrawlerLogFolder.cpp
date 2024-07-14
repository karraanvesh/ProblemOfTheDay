// Time  Complexity : O(n)
// Space Complexity : O(n)
// where n are the number of folders in given logs

// Problem Link : https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();

        stack<string> st;

        st.push("Main");

        for(int i = 0 ; i < n ; i++) {

            string str = logs[i];

            if(str.compare("./") == 0) continue;

            if(str.compare("../") == 0) {

                if(st.size() > 1)
                st.pop();
            }

            else {
                st.push(str);
            }
        }

        int result = st.size() - 1;

        return result;
    }
};