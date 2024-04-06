// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=daily-question&envId=2024-04-06

class Solution {
    private :
    bool isChar(char ch) {
        return (ch >= 'a' and ch <= 'z');
    }
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        set<int> arr;
        stack<pair<char , int>> st;

        for(int i = 0 ; i < n ; i++) {

            if(isChar(s[i]))
            continue;

            if(s[i] == '(') {
                st.push({'(' , i});
            }

            else {

                if(st.empty()) {
                    arr.insert(i);
                }

                else {
                    st.pop();
                }
            }
        }

        while(!st.empty()) {
            int ind = st.top().second;

            st.pop();

            arr.insert(ind);
        }

        string result;

        for(int i = 0 ; i < n ; i++) {

            if(arr.count(i) == 0) {
                result += s[i];
            }
        }

        return result;
    }
};