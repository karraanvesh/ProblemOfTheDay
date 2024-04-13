// Time  Complexity : O(log x) + O(32) ~ O(log x)
// Space Complexity : O(32) ~ O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/reverse-bits3556/1

class Solution {
  public:
    long long reversedBits(long long x) {
        vector<int> arr(32 , 0);
        
        int ind = 0;
        while(x > 0) {
            
            if(x & 1)
            arr[ind] = 1;
            
            x /= 2;
            ind++;
        }
        
        reverse(arr.begin() , arr.end());
        
        int p = 0;
        long long result = 0;
        
        for(int i = 0 ; i <= 31 ; i++) {
            
            if(arr[i])
            result += pow(2 , i);
            
            p++;
        }
        
        return result;
    }
};