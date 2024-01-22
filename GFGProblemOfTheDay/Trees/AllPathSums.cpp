// Time Complexity : O(n)
// Space Complexity : O(paths) + O(h) (height of the tree for auxilary stack space)
// where paths are the number of paths which sums to target 

// Problem Link : https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

class Solution
{
    private:
    void pathSum(Node *root , int &sum , vector<int> &path , vector<vector<int>> &allPaths , int target) {
        if(!root) return ;
        
        int val = root->key;
        sum += val;
        path.push_back(val);
        
        if(sum == target) {
            allPaths.push_back(path);
        }
        
        pathSum(root->left , sum , path , allPaths , target);
        pathSum(root->right , sum , path , allPaths , target);
        
        sum -= val;
        path.pop_back();
        
        return ;
    }
    public:
    vector<vector<int>> printPaths(Node *root, int target)
    {
        vector<vector<int>> allPaths;
        vector<int> path;
        int sum = 0;
        
        pathSum(root , sum , path , allPaths , target);
        
        return allPaths;
    }
};