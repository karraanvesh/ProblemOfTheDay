// Time  Complexity : O(r * n)
// Space Complexity : O(length of s)

// Problem Link : https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        
        while(r--) {
            string str = "";
            
            for(int i = 0 ; i <= n ; i++) {
                
                if(s[i] == '1')
                str += "10";
                
                else
                str += "01";
            }
            
            s = str;
        }
        
        char result = s[n];
        
        return result;
    }
};