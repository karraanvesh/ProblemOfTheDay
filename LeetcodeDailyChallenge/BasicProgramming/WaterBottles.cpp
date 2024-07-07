// Time  Complexity : O(log number_of_full_bottles_formed)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/water-bottles/?envType=daily-question&envId=2024-07-07

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        
        int result = 0, empty = 0 , fullBottles;

        result += numBottles;
        empty += numBottles;

        while((empty / numExchange) >= 1) {

            fullBottles = empty / numExchange;
            empty = empty - (fullBottles * numExchange);
            result += fullBottles;

            empty += fullBottles;
        }

        return result;
    }
};