// Time  Complexity : O(n ^ 2)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/?envType=daily-question&envId=2024-07-11

class Solution {
    private : 
    void reverseStr(string &str , int left , int right) {
        
        while(left < right) {
            swap(str[left] , str[right]);
            
            left++;
            right--;
        }
        
        return ;
    }
public:
    string reverseParentheses(string s) {
        int n = s.length();
        
        string str = s;
        stack<int> st;
        
        for(int i = 0 ; i < n ; i++)    {
            if(s[i] == '(')
                st.push(i);
            
            else if(s[i] == ')')             {
                int start = st.top();
                st.pop();
                
                reverseStr(str , start + 1 , i-1);
            }
                
        }
        
        string result;
        
        for(int i = 0 ; i < n ; i++)    {
            if(str[i] == ')' or str[i] == '(')
                continue;
            
            result += str[i];
        }
        
        return result;
    }
};