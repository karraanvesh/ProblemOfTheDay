// Time Complexity : O(n)
// Space Complexity : O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 or n == 2)
        return n;

        int prev1 , prev2 , curr;
        prev1 = 2;
        prev2 = 1;

        for(int i = 3 ; i <= n ; i++) {
            int oneStep , twoSteps = 0;

            oneStep = prev1;
            if(i >= 2)
            twoSteps = prev2;

            curr = oneStep + twoSteps;

            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};