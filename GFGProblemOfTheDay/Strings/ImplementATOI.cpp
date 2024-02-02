// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/implement-atoi/1

class Solution{
    private :
    bool isDigit(char ch) {
        return (ch >= '0' and ch <= '9');
    }
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        int n = s.length();
        int num = 0;
        bool flag = false;
        
        if(!isDigit(s[0])) {
            
            if(s[0] == '-')
            flag = true;
            
            else
            return -1;
        }
        
        else {
            num = num*10 + (s[0] - '0');
        }
        
        for(int i = 1 ; i < n ; i++) {
            
            if(!isDigit(s[i]))
            return -1;
            
            num = num*10 + (s[i] - '0');
        }
        
        if(flag)
        num = num * -1;
        
        return num;
    }
};