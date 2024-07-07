// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/pass-the-pillow/?envType=daily-question&envId=2024-07-06

class Solution {
public:
    int passThePillow(int n, int time) {
        n--;

        int turnsCompleted = time / n;
        int rem = time%n;

        if(turnsCompleted%2 == 1)
        return ((n + 1) - rem);

        return 1 + rem;
    }
};