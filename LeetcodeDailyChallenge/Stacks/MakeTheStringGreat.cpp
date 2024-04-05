// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/make-the-string-great/?envType=daily-question&envId=2024-04-05

class Solution {
    private :
    bool isRemovable(char a , char b) {
        return ((a + 32 == b) or (b + 32 == a));
    }
public:
    string makeGood(string s) {
        int n = s.length();

        stack<char> st;

        for(int i = 0 ; i < n ; i++) {
            char ch = s[i];

            if(st.empty()) {
                st.push(ch);
            }

            else {
                char prevChar = st.top();

                if(isRemovable(ch , prevChar)) {
                    st.pop();
                }

                else {
                    st.push(ch);
                }
            }
        }

        string result;

        while(!st.empty()) {
            char ch = st.top();

            st.pop();

            result += ch;
        }

        reverse(result.begin() , result.end());

        return result;
    }
};