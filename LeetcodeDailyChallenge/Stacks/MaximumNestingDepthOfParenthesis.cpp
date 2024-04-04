// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/?envType=daily-question&envId=2024-04-04

class Solution {
public:
    int maxDepth(string s) {
        int n = s.length();

        int result = 0;
        stack<pair<char , int>> st;

        for(int i = 0 ; i < n ; i++) {

            if(s[i] == '(') {

                if(st.empty()) {
                    st.push({'(' , 1});
                    result = max(result , 1);
                }

                else {
                    int len = st.top().second;

                    st.push({'(' , len + 1});

                    result = max(result , len + 1);
                }
            }

            else if(s[i] == ')'){
                st.pop();
            }
        }

        return result;
    }
};