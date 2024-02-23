// Time Complexity : O(n * 2 * k) ~ O(n * k)
// Space Complexity : O(n * k * 2) ~ O(n * k) + O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1

class Solution
{
    private :
    int f(int ind , vector<int> &price , bool flag , int k , int n , 
    vector<vector<vector<int>>> &dp) {
        
        if(ind == n) return 0;
        
        if(k == 0) return 0;
        
        if(dp[ind][flag][k] != -1) return dp[ind][flag][k];
        
        if(!flag) {
            
            int buy = (price[ind] * -1) + f(ind+1 , price , !flag , k , n , dp);
            int dontBuy = f(ind + 1 , price , flag , k , n , dp);
            
            return dp[ind][flag][k] = max(buy , dontBuy);
        }
        
        else {
            
            int sell = price[ind] + f(ind+1 , price , !flag , k-1 , n , dp);
            int dontSell = f(ind+1 , price , flag , k , n , dp);
            
            return dp[ind][flag][k] = max(sell , dontSell);
        }
        
    }
    public:
    //User function Template for C++
    int maxProfit(vector<int> &price){
        int n = price.size();
        
        int k = 2;
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(2 , vector<int>(k+1 , -1)));
        return f(0 , price , false , k , n , dp);
    }
};