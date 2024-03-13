// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13

class Solution {
public:
    int pivotInteger(int n) {
        int prefixSum , suffixSum;
        prefixSum = suffixSum = 0;
        int totalSum = (n * (n + 1)) / 2;
        int pivot = -1;

        for(int i = 1 ; i <= n ; i++) {
            prefixSum += i;
            suffixSum = totalSum - prefixSum + i;

            if(prefixSum == suffixSum) {
                pivot = i;
                break;
            }
        }

        return pivot;
    }
};