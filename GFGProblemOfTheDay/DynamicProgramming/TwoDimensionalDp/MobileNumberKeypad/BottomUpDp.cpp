// Time Complexity : O(10 * n) ~ O(n)
// Space Complexity: O(10 * n) ~ O(n)

class Solution {
  public:
    long long getCount(int n) {
        map<int , vector<int>> mp;
        
        mp[0].push_back(0);
        mp[0].push_back(8);
        
        mp[1].push_back(1);
        mp[1].push_back(2);
        mp[1].push_back(4);
        
        
        mp[2].push_back(2);
        mp[2].push_back(1);
        mp[2].push_back(3);
        mp[2].push_back(5);
        
        mp[3].push_back(3);
        mp[3].push_back(2);
        mp[3].push_back(6);
        
        mp[4].push_back(1);
        mp[4].push_back(4);
        mp[4].push_back(5);
        mp[4].push_back(7);
        
        mp[5].push_back(5);
        mp[5].push_back(2);
        mp[5].push_back(4);
        mp[5].push_back(6);
        mp[5].push_back(8);
        
                
        mp[6].push_back(6);
        mp[6].push_back(3);
        mp[6].push_back(5);
        mp[6].push_back(9);
        
        mp[7].push_back(7);
        mp[7].push_back(4);
        mp[7].push_back(8);
        
        mp[8].push_back(0);
        mp[8].push_back(5);
        mp[8].push_back(7);
        mp[8].push_back(9);
        mp[8].push_back(8);
        
        mp[9].push_back(6);
        mp[9].push_back(8);
        mp[9].push_back(9);
        
        long long result = 0;
        vector<vector<long long>> dp(10 , vector<long long>(n+1 , 0));
        
        for(int digit = 0 ; digit <= 9 ; digit++) {
            dp[digit][0] = 1;
        }
            
        for(int temp = 1 ; temp <= n ; temp++) {
            
            for(int digit = 0 ; digit <= 9 ; digit++) {
                
                long long ct = 0;
        
                vector<int> v = mp[digit];
                
                for(int i = 0 ; i < v.size() ; i++) {
                    
                    ct = ct + dp[v[i]][temp-1];
                }
                
                dp[digit][temp] = ct;
            }
        }
        
        for(int digit = 0 ; digit <= 9 ; digit++) {
            result += dp[digit][n-1];
        }
        
        return result;
    }
};