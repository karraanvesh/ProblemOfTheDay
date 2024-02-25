
// Time Complexity : O(n * sqrt(n)) + O(n) 
// Space Complexity : O(n) + O(n) 

// Problem Link : https://leetcode.com/problems/greatest-common-divisor-traversal/description/?envType=daily-question&envId=2024-02-25

class Solution {
    void dfs(int node , vector<int> adj[] , vector<bool> &visited , int &ct) {
        ct++;
        visited[node] = true;

        for(int &neigh : adj[node]) {

            if(!visited[neigh]) {
                dfs(neigh , adj , visited , ct);
            }
        }

        return ;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        map<int , vector<int>> mp;

        for(int i = 0 ; i < n ; i++) {
            int num = nums[i];

            for(int j = 2 ; j <= sqrt(num) ; j++) {

                if(num%j == 0) {
                    mp[j].push_back(i);

                    while(num%j == 0) {
                        num /= j;
                    }

                    if(num == 1)
                    break;
                }
            }

            if(num >= 2)
            mp[num].push_back(i);

        }

        map<int , vector<int>> :: iterator itr;
        vector<int> adj[n];
        
        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            vector<int> neighbours = itr->second;

            int totalNeighbours = neighbours.size();

            for(int i = 1 ; i < totalNeighbours ; i++) {
                adj[neighbours[0]].push_back(neighbours[i]);
                adj[neighbours[i]].push_back(neighbours[0]);
            }
        }

        int ct = 0;
        vector<bool> visited(n , false);

        dfs(0 , adj , visited , ct);

        return (ct == n);
    }
};