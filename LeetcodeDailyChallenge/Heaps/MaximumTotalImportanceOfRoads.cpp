// Time Complexity : O(nlogn + (NumberOfNodesInPq * log NumberOfNodesInPq))
// Space Complexity : O(n) + O(V + 2E)

// Problem Link : https://leetcode.com/problems/maximum-total-importance-of-roads/?envType=daily-question&envId=2024-06-28

class Solution {
    private :
    static bool comp(pair<int , int> &p1 , pair<int , int> &p2) {

        return p1.second > p2.second;
    }
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        vector<int> indegree(n , 0);
        vector<int> adj[n];

        for(int i = 0 ; i < m ; i++) {

            int u = roads[i][0];
            int v = roads[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            indegree[u]++;
            indegree[v]++;
        }

        vector<pair<int , int>> vect;

        for(int i = 0 ; i < n ; i++) {
            vect.push_back({i , indegree[i]});
        }

        sort(vect.begin() , vect.end() , comp);

        vector<long long> values(n , 0) , sum(n , 0);

        priority_queue< pair< pair<long long , long long> , int> > pq;

        for(int i = 0 ; i < n ; i++) {
            pq.push({ {0 , vect[i].second} , vect[i].first });
        }

        int ct = n;

        while(!pq.empty() and ct > 0) {

            int node = pq.top().second;

            pq.pop();

            if(values[node])
            continue;

            values[node] = ct;

            for(int &neigh : adj[node]) {

                if(values[node])
                continue;

                values[neigh] += ct;

                pq.push({{values[neigh] , vect[neigh].second} , neigh});
            }

            ct--;

        }

        long long result = 0;
        
        for(int i = 0 ; i < m ; i++) {

            int u = roads[i][0];
            int v = roads[i][1];

            result += (values[u] + values[v]);
        }

        return result;
    }
};