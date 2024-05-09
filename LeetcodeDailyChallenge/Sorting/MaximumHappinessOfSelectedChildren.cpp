// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2024-05-09

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end());

        long long ct = 0 , score = 0;
        int n = happiness.size();

        for(int i = n - 1 ; i >= 0 ; i-- , k-- , ct++) {

            if(k > 0) {
                if(ct >= happiness[i])
                continue;

                score += (happiness[i] - ct);
            } else {
                break;
            }
        }

        return score;
    }
};