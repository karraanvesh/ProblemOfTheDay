// Time  Complexity : O(n * n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/recursive-sequence1611/1

class Solution{
public:
    long long sequence(int n){
        long long result , val;
        result = 0;
        val = 1;
        long mod = 1e9 + 7;
        
        for(int i = 1 ; i <= n ; i++) {
            long long prod = 1;
            
            for(int j = 1 ; j <= i ; j++) {
                prod = (prod%mod * val%mod)%mod;
                val++;
            }
            
            result = (result%mod + prod%mod)%mod;
        }
        
        return result;
    }
};