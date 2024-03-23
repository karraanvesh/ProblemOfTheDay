// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/fibonacci-series-up-to-nth-term/1

class Solution {
  public:
    vector<int> Series(int n) {
        vector<int> result;
        result.push_back(0);
        
        if(n == 0) {
            return result;
        }
        
        result.push_back(1);
        
        if(n == 1) return result;
        
        long prev2 , prev1 , mod = 1e9 + 7;
        prev2 = 0;
        prev1 = 1;
    
        
        for(int i = 2 ; i <= n ; i++) {
            long currNum = (prev2%mod + prev1%mod)%mod;
            result.push_back(currNum);
            
            prev2 = prev1;
            prev1 = currNum;
        }
        
        return result;
    }
};