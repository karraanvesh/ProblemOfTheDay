// Time Complexity  : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30

class Solution {
    private :
    bool isOperator(string &str) {
        int len = str.length();

        if(len == 1) {

            if(str[0] == '+' or str[0] == '-' or str[0] == '*' or str[0] == '/')
            return true;
        }

        return false;
    }
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;

        for(int i = 0 ; i < n ; i++) {

            string str = tokens[i];

            if(isOperator(str)) {
                int op1 , op2;
                op2 = st.top();
                st.pop();
                op1 = st.top();
                st.pop();

                char ch = str[0];
                int value;

                switch(ch) {
                    case '+' : value = op1 + op2;
                    break;

                    case '-' : value = op1 - op2;
                    break;

                    case '*' : value = op1 * op2;
                    break;

                    case '/' : value = op1 / op2;
                    break;
                }

                st.push(value);

            } else {
                int num = 0;
                int len = str.length();

                int j = 0;
                bool flag = false;

                if(str[j] == '-') {
                    j++;
                    flag = true;
                }

                for( ; j < len ; j++) {
                    num = num * 10 + (str[j] - '0');
                }

                if(flag)
                num = num * -1;

                st.push(num);
            }
        }

        int ans = st.top();

        return ans;
    }
};