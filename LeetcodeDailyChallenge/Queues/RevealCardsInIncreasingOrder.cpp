// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();

        queue<int> q;
        sort(deck.begin() , deck.end());

        vector<int> result(n , 0);

        for(int i = 0 ; i < n ; i++) {
            q.push(i);
        }

        int ind = 0;

        while(!q.empty()) {
            int firstInd = q.front();
            q.pop();
            int secondInd = q.front();
            q.pop();

            result[firstInd] = deck[ind];
            ind++;

            q.push(secondInd);
        }

        return result;
    }
};