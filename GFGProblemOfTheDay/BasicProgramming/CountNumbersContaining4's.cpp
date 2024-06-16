// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/count-numbers-containing-43022/1

class Solution {
    private :
    int countOf4(int num) {
        int ct = 0;
        
        while(num > 0) {
            
            if(num%10 == 4)
            ct++;
            
            num /= 10;
        }
        
        return ct;
    }
  public:
    int countNumberswith4(int n) {
        
        int result = 0;
        for(int i = 1 ; i <= n ; i++) {
            
            int ct = countOf4(i);
            
            if(ct)
            result++;
        }
        
        return result;
    }
};