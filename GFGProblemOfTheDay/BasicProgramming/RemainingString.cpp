// User function template for C++

// Time Complexity: O(n)
// Space Complexity: O(n - x)
// where x is the index final count of ch 

// Problem Link : https://www.geeksforgeeks.org/problems/remaining-string3515/1

class Solution {
  public:

    string printString(string s, char ch, int count) {
        
        int n = s.length() , ind = n;
        int ct = 0;
        
        for(int i = 0 ; i < n ; i++) {
            
            if(s[i] == ch)
            ct++;
            
            if(ct == count) {
                ind = i+1;
                break;
            }
        }
        
        string result;
        
        for(int i = ind ; i < n ; i++) {
            
            result += s[i];
        }
        
        return result;
    }
};
