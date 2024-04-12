// Time  Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        
       int minTurns = tickets[k];
        
        int result = 0;
        
        for(int i = 0 ; i < n ; i++) {
            result += min(minTurns , tickets[i]);
        }

        for(int i = k+1 ; i < n ; i++) {

            if(tickets[i] >= minTurns) {
                result--;
            }
        }

        return result;
    }
};