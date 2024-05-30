// Time  Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)

class Solution {
    private :
    int mod = 1e9 + 7;
  public:
    int countWays(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        
        vector<int> prev(m + 1 , 0);
        prev[0] = 1;
        
        for(int i = 1 ; i <= n ; i++) {
            
            vector<int> curr(m + 1 , 0);
            curr[0] = 1;
            
            for(int j = 1 ; j <= m ; j++) {
                
                if(s1[i - 1] == s2[j - 1]) {
                    curr[j] = (prev[j-1]%mod + prev[j]%mod)%mod;
                }
                
                else
                curr[j] = prev[j]%mod;
            }
            
            prev = curr;
        }
        
        
        return prev[m];
    }
};