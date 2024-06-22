// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/extract-the-number-from-the-string3428/1

class Solution {
    private :
    bool isDigit(char ch) {
        return (ch >= '0' and ch <= '9');
    }
  public:
    long long ExtractNumber(string str) {
        int n = str.length();
        
        long long result = -1;
        
        for(int i = 0 ; i < n ; ) {
            
            if(!isDigit(str[i])) {
                i++;
                continue;
            }
            
            long long num = 0;
            bool flag = false;
            
            while(i < n and isDigit(str[i])) {
                num = num*10 + (str[i] - '0');
                
                if(str[i] == '9')
                flag = true;
                
                i++;
            }
            
            if(!flag)
            result = max(result , num);
            
        }
        
        return result;
    }
};