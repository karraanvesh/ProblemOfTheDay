// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/bag-of-tokens/?envType=daily-question&envId=2024-03-04

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();

        sort(tokens.begin() , tokens.end());

        int left , right;
        left = 0;
        right = n - 1;
        int score = 0;

        while(left <= right) {

            if(left == right) {
                if(power >= tokens[left]) {
                    score++;
                }
                break;
            }

            if(power >= tokens[left]) {
                power = power - tokens[left];
                score++;
                left++;
            }

            else if(score >= 1){
                power += tokens[right];
                right--;
                score--;
            }

            else {
                break;
            }
        }

        return score;
    }
};