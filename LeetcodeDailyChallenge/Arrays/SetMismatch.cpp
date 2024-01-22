// Time Complexity  : O(n)
// Space Complexity : O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        long sumOfN = (n * (n+1)) / 2;
        long sum , sumOfSquare , sumOfSquareN;
        sum = sumOfSquare = sumOfSquareN = 0;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
            sumOfSquare += (nums[i] * nums[i]);
            sumOfSquareN += ((i+1) * (i+1));
        }

       
        long eq1 , eq2;
        eq1 = sumOfN - sum;
        eq2 = sumOfSquareN - sumOfSquare;
        eq2 = eq2 / eq1;


        int missing = (eq1 + eq2) / 2;
        int repeated = eq2 + (-1 * missing);

        vector<int> result;

        result.push_back(repeated);
        result.push_back(missing);

        return result;
    }
};