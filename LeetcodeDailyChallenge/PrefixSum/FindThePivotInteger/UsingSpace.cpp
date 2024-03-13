// Time  Complexity : O(2 * n) ~ O(n)
// Space Complexity : O(2 * n) ~ O(n)

// Problem Link : https://leetcode.com/problems/find-the-pivot-integer/?envType=daily-question&envId=2024-03-13

class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1 , 0) , suffix(n+2 , 0);

        for(int i = 1 ; i <= n ; i++) {
            prefix[i] = prefix[i-1] + i;
            suffix[n - i + 1] = suffix[n - i + 2] + (n - i + 1);
        }

        int pivot = -1;

        for(int i = 1 ; i <= n ; i++) {
            if(prefix[i] == suffix[i]) {
                pivot = i;
                break;
            }
        }

        return pivot;
    }
};