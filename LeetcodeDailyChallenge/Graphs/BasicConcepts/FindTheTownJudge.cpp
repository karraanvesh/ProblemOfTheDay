// Time  Complexity : O(n + m)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/find-the-town-judge/description/?envType=daily-question&envId=2024-02-22

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n+1 , 0) , outdegree(n+1 , 0);

        int m = trust.size();
        for(int i = 0 ; i < m ; i++) {
            int u = trust[i][0];
            int v = trust[i][1];

            indegree[v]++;
            outdegree[u]++;
        }

        int judge = -1;
        for(int i = 1 ; i <= n ; i++) {

            if(outdegree[i] == 0 and indegree[i] == n-1) {
                judge = i;
                break;
            }
        }

        return judge;
    }
};