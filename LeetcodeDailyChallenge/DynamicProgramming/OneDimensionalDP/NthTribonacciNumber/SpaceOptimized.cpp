// Time  Complexity : O(n)
// Space Complexity : O(1) 

class Solution {
public:
    int tribonacci(int n) {

        if(n == 0) return 0;

        if(n <= 2) return 1;

        int prev1 , prev2 , prev3;
        prev1 = 0;
        prev2 = prev3 = 1;

        for(int i = 3 ; i <= n ; i++) {
            int curr = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }

        return prev3;
    }
};