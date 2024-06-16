// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1

class Solution {
  public:
    string armstrongNumber(int n){
        int armstrongNum , temp = n;
        armstrongNum = 0;
        
        while(n > 0) {
            int rem = n%10;
            armstrongNum += (rem * rem * rem);
            
            n /= 10;
        }
        
        string result;
        
        if(temp == armstrongNum)
        result = "Yes";
        
        else 
        result = "No";
        
        return result;
    }
};