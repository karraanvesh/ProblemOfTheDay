/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// Time  Complexity : O(3 * n) ~ O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16

class Solution {
    private :
    int noOfNodes(TreeNode *root) {

        int ct = 0;

        queue<TreeNode*> q;
        TreeNode *node = root;

        q.push(node);

        while(!q.empty()) {
            TreeNode *currNode = q.front();

            q.pop();

            ct++;

            if(currNode->left)
            q.push(currNode->left);

            if(currNode->right)
            q.push(currNode->right);
        }

        return ct;
    }

    void buildGraph(TreeNode *root , vector<pair<int , int>> adj[]) {

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            TreeNode *currNode = q.front();

            q.pop();

            int u =  currNode->val , v;

            if(currNode->left) {
                v = currNode->left->val;

                adj[u].push_back({v , 1});
                adj[v].push_back({u , 0});

                q.push(currNode->left);
            }

            if(currNode->right) {
                v = currNode->right->val;

                adj[u].push_back({v , 2});
                adj[v].push_back({u , 0});

                q.push(currNode->right);
            }
        }

        return ;
    }

    void dfs(int node , int target , vector<pair<int , int>> adj[] , vector<bool> &visited , vector<int> &path , vector<int> &result) {

        visited[node] = true;

        if(node == target) {
            result = path;
        }

        for(pair<int , int> &neigh : adj[node]) {
            
            int nextNode = neigh.first;
            int dir = neigh.second;

            if(!visited[nextNode]) {
                cout << nextNode << endl;
                path.push_back(dir);
                dfs(nextNode , target , adj , visited , path , result);

                path.pop_back();
            }
        }

        return ;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {

        int n = noOfNodes(root);
        vector<pair<int , int>> adj[n+1];

        buildGraph(root , adj);

        vector<bool> visited(n+1 , false);
        vector<int> path  , result;

        dfs(startValue , destValue , adj , visited , path , result);

        string directions;
        int m = result.size();

        for(int i = 0 ; i < m ; i++) {

            if(result[i] == 0)
            directions += "U";

            else if(result[i] == 1)
            directions += "L";

            else
            directions += "R";
        }

        return directions;
    }
};
