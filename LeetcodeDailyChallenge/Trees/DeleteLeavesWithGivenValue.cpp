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

// Time  Complexity : O(n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/delete-leaves-with-a-given-value/?envType=daily-question&envId=2024-05-17

class Solution {
    private :
    bool isLeaf(TreeNode *root) {
        return (!root->left and !root->right);
    }
    void dfs(TreeNode *root , TreeNode *parent , char ch , int target) {

        if(root == NULL) return ;

        dfs(root->left , root , 'L' , target);
        dfs(root->right , root , 'R' , target);

        if(isLeaf(root) and target == root->val) {

            if(ch == 'L') {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        }

        return ;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        
        dfs(root , NULL , 'N' , target);

        if(isLeaf(root) and target == root->val)
        root = NULL;

        return root;
    }
};