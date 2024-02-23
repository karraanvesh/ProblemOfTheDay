// Time  Compexity : O(n * k * 2) ~ O(n * k)
// Space Complexity : O(2 * n * 2) ~ O(n)

class Solution
{
    public:
    //User function Template for C++
    int maxProfit(vector<int> &price){
        int n = price.size();
        
        int k = 2;
        
        vector<vector<int>> prev(n+1 , vector<int>(2 , 0));
        
        for(int currTrans = k ; currTrans >= 1 ; currTrans--) {
            vector<vector<int>> curr(n+1 , vector<int>(2 , 0));
            
            for(int ind = n-1 ; ind >= 0 ; ind--) {
                
                for(int flag = 0 ; flag <= 1 ; flag++) {
                    
                    if(!flag) {
                        
                        int buy = (price[ind] * -1) + curr[ind+1][!flag];
                        int dontBuy = curr[ind+1][flag];
                        
                        curr[ind][flag] = max(buy , dontBuy);
                    }
                    
                    else {
                        
                        int sell = price[ind] + prev[ind+1][!flag];
                        int dontSell = curr[ind+1][flag];
                        
                        curr[ind][flag] = max(sell , dontSell);
                    }
                }
            }
            
            prev = curr;
        }
        
        return prev[0][0];
    }
};