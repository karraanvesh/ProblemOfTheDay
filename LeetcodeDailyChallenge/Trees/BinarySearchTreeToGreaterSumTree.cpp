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

// Time Complexity : O(n)
// Space Complexity : O(h) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/?envType=daily-question&envId=2024-06-25

class Solution {
    private :
    void f(TreeNode* root , int &sum) {

        if(root  == NULL) return ;

        f(root->right , sum);

        root->val = sum + root->val;
        sum = root->val;

        f(root->left , sum);

        return ;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum =  0;

        f(root , sum);
        return root;
    }
};