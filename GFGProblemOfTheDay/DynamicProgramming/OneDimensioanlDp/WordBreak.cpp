// Time Complexity : O(n * n)
// Space Complexity : O(n) + O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/word-break1352/1

class Solution
{
    private :
    int isPossible(string &str , int ind , set<string> &st , int n , vector<int> &dp) {
        
        if(ind == n) {
            return true;
        }
        
        if(dp[ind] != -1) return dp[ind];
        
        string currStr;
        bool result = false;
        
        for(int i = ind ; i < n ; i++) {
            currStr += str[i];
            
            if(st.count(currStr)) {
                
                if(isPossible(str , i+1 , st , n , dp)) {
                    result = true;
                    break;
                }
            }
        }
        
        return dp[ind] = result;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        int n = A.length();
        
        set<string> st;
        int m = B.size();
        
        for(int i = 0 ; i < m ; i++) {
            st.insert(B[i]);
        }
        
        vector<int> dp(n , -1);
        
        return isPossible(A , 0 , st , n , dp);
    }
};