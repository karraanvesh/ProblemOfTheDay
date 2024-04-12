// Time  Complexity : O(n * n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        
        deque<int> dq , index;
        
        for(int i = 0 ; i < n ; i++) {
            dq.push_back(tickets[i]);
            index.push_back(i);
        }
        
        int totalTime = 0;
        
        while(true) {
            int ind = index.front();
            int currEle = dq.front();
            
            dq.pop_front();
            index.pop_front();
            
            currEle--;
            

            totalTime++;
            
            if(currEle == 0 and ind == k)
                break;
            
            if(currEle) {
                dq.push_back(currEle);
                index.push_back(ind);
            }
        }
        
        return totalTime;
    }
};