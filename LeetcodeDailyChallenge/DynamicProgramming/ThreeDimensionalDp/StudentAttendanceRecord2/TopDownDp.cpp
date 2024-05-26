// Time  Complexity : O(n * 2 * 3) ~ O(n)
// Space Complexity : O(n * 2 * 3) ~ O(n)

// Problem Link : https://leetcode.com/problems/student-attendance-record-ii/description/
class Solution {
    private :
    long mod = 1e9 + 7;

    long f(int n , int absentCt , int lateCt , vector<vector<vector<long>>> &dp) {

        if(absentCt >= 2 or lateCt >= 3) return 0;

        if(n == 0) return 1;

        if(dp[n][absentCt][lateCt] != -1) return dp[n][absentCt][lateCt];

        return dp[n][absentCt][lateCt] = (f(n -1 , absentCt , 0 , dp)%mod + f(n - 1 , absentCt + 1 , 0 , dp)%mod + f(n -1 , absentCt , lateCt + 1, dp)%mod)%mod;
    }
public:
    long checkRecord(int n) {
        vector<vector<vector<long>>> dp(n+1 , vector<vector<long>>(2 , vector<long>(3 , -1)));

        return f(n , 0 , 0 , dp);
    }
};