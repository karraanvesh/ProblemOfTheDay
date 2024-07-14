// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        int startTime = customers[0][0];
        double result = 0.0;

        for(int i = 0 ; i < n ; i++) {

            int endTime = startTime + customers[i][1];

            int waitingTime = endTime - customers[i][0];

            result += waitingTime;

            startTime = endTime;

            if(i < n-1) {

                if(customers[i+1][0]  > startTime)
                startTime = customers[i+1][0];
            }
        }

        result = ((double) result / n);

        return result;
    }
};