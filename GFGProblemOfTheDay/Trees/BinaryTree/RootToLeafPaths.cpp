// Time  Complexity : O(n)
// Space Complexity : O(2 ^ h)

// Problem Link : https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

class Solution {
    private :
    void dfs(Node *root , vector<int> &path , vector<vector<int>> &result) {
        
        if(root == NULL) return ;
        
        path.push_back(root->data);
        
        dfs(root->left , path , result);
        dfs(root->right , path , result);
        
        if(!root->left and !root->right) {
            result.push_back(path);
        }
        
        path.pop_back();
        
        return ;
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> result;
        
        vector<int> path;
        
        dfs(root , path , result);
        
        return result;
    }
};