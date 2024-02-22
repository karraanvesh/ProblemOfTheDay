// Time Complexity : O(n * m)
// Space Complexity : O(2 * m) ~ O(m)

class Solution
{
    private :
    int mod = 1e9 + 7;
    public:
    int subsequenceCount(string s, string t)
    {
        int n = s.length();
        int m = t.length();
    
        vector<int> prev(m+1 , 0);
        prev[0] = 1;
        
        for(int i = 1 ; i <= n ; i++) {
            
            vector<int> curr(m+1 , 0);
            curr[0] = 1;
            
            for(int j = 1 ; j <= m ; j++) {
                
                if(s[i-1] == t[j-1]) {
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