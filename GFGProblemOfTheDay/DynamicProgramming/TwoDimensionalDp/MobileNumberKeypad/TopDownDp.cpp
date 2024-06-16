// Time Complexity : O(10 * n) ~ O(n)
// Space Complexity: O(10 * n) ~ O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1

class Solution {
    private : 
    long long f(int digit , int n , map<int , vector<int>> &mp , vector<vector<long long>> &dp) {
        
        if(n == 0) return 1;
        
        if(dp[digit][n] != -1) return dp[digit][n];
        
        long long ct = 0;
        
        vector<int> v = mp[digit];
        
        for(int i = 0 ; i < v.size() ; i++) {
            
            ct += f(v[i] , n - 1 , mp , dp);
        }
        
        return dp[digit][n] = ct;
    }
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
        vector<vector<long long>> dp(10 , vector<long long>(n+1 , -1));
        
        
        for(int i = 0 ; i <= 9 ; i++) {
            long long ct = f(i , n - 1 , mp , dp);
            
            result += ct;
        }
        
        return result;
    }
};