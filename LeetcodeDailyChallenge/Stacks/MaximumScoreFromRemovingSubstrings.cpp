// Time  Complexity : O(8 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/maximum-score-from-removing-substrings/description/?envType=daily-question&envId=2024-07-12

class Solution {
    private :
    int calcScore(string &s , int x , int y , char ch1 , char ch2) {
        int n = s.length();
        
        stack<int> st;
        int score = 0;

        for(int i = 0 ; i < n ; i++)    {
            char ch = s[i];
            
            if(!st.empty()) {
                
                if(ch == ch1 and st.top() == ch2)  {
                    score += (ch2 == 'b') ? y : x;
                    st.pop();
                  }
                
                else 
                    st.push(ch);
            }
            
            else 
                st.push(ch);
        }
        
        string temp;
        
        while(!st.empty()) {
            char ch = st.top();
            
            st.pop();
            
            temp += ch;
        }
        
        reverse(temp.begin() , temp.end());
        
        int m = temp.length();
        
        for(int i = 0 ; i < m ; i++)    {
            char ch = temp[i];
            
            if(!st.empty()) {
                
                if(ch == ch2 and st.top() == ch1)  {
                    score += (ch1 == 'a') ? x : y;
                    st.pop();
                  }
                else 
                    st.push(ch);
            }
            
            else 
                st.push(ch);
        }

        return score;
    }
public:
    int maximumGain(string s, int x, int y) {

        int score1 = calcScore(s , x , y , 'b' , 'a');
        int score2 = calcScore(s , x , y , 'a' , 'b');
        
        int result = max(score1 , score2);
        
        return result;
    }
};