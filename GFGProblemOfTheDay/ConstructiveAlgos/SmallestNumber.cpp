// User function Template for C++

// Time  Complexity : O(d)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/smallest-number5829/1

class Solution {
  public:
    string smallestNumber(int s, int d) {
        int maxNumber = 9*d;
        
        string result;
        
        if(s > maxNumber) {
            result = "-1";
            return result;
        }
        
        int num = 1 , i = 0;
        
        while(i < 1 and (9 * (d - i - 1)) >= (s - num)) {
            result += ('0' + num);
            i++;
            s -= num;
        } 
        
        num = 0;
        
        while(i < d) {
            
            while(i < d and (9 * (d - i - 1)) >= (s - num)) {
                result += ('0' + num);
                i++;
                s -= num;
            } 
            
            num = num + ((s - (9 * (d - i - 1))) - num);
        }
        
        
        return result;
    }
};
