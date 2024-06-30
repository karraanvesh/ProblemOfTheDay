// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/summed-matrix5834/1

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        if(q == 1 or q > 2*n) return 0;
        
        long long maxFreq = n , maxEle = n + 1;
        long long diff = abs(maxEle - q);
        long long result = n - diff;
        
        return result;
    }
};