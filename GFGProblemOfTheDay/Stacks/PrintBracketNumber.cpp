// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

class Solution {
    private :
    bool isLowerCase(char ch) {
        return (ch >= 'a' and ch <= 'z');
    }
  public:

    vector<int> bracketNumbers(string str) {
        int n = str.length();
        
        stack<int> st;
        int ct = 0;
        vector<int> result;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(isLowerCase(str[i]))
            continue;
            
            if(str[i] == '(') {
                ct++;
                result.push_back(ct);
                st.push(ct);
            }
            
            else {
                result.push_back(st.top());
                st.pop();
            }
        }
        
        return result;
    }
};