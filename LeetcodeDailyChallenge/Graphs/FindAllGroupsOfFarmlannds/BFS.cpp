// Time  Complexity : O(n * m)
// Space Complexity : O(n * m)

class Solution {
    private :
    bool isSafe(int i , int j , int n , int m) {
        return (i >= 0 and i < n and j >= 0 and j < m);
    }
    void bfs(int i , int j , vector<vector<int>> &land , vector<vector<bool>> &visited , int &num , 
    map<int , pair<int,int>> &mp , int n , int m) {
        
        visited[i][j] = true;

        int dirRow[] = {-1 , 1 , 0 , 0};
        int dirCol[] = {0 , 0 , -1 , 1};

        queue<pair<int , int>> q;

        q.push({i , j});

        while(!q.empty()) {
            int currRow = q.front().first;
            int currCol = q.front().second;

            q.pop();

            int ind = currRow * m + currCol;
            mp.insert({ind , {currRow , currCol}});

            num = max(num , ind);

            for(int k = 0 ; k < 4 ; k++) {

            int newRow = currRow + dirRow[k];
            int newCol = currCol + dirCol[k];

                if(isSafe(newRow , newCol , n , m) and land[newRow][newCol] and !visited[newRow][newCol]) {
                    q.push({newRow , newCol});
                    visited[newRow][newCol] = true;
                }
            }
        }

        return ;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> result;

        int n = land.size();
        int m = land[0].size();
        vector<vector<bool>> visited(n , vector<bool>(m ,false));

        for(int i = 0 ; i < n ; i++) {

            for(int j = 0 ; j < m ; j++) {

                if(land[i][j] and !visited[i][j]) {
                    // start i , j
                    int num = i*m + j;
                    map<int , pair<int , int>> mp;

                    bfs(i , j , land , visited , num , mp , n , m);

                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);

                    pair<int ,int> p = mp[num];
                    v.push_back(p.first);
                    v.push_back(p.second);

                    result.push_back(v);
                }
            }
        }

        return result;
    }
};