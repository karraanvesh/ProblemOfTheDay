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
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/sum-root-to-leaf-numbers/?envType=daily-question&envId=2024-04-15

class Solution {
    private :
    void dfs(TreeNode *root , int &sum , int &totalSum) {
        if(root == NULL) return ;

        sum = sum * 10 + root->val;

        dfs(root->left , sum , totalSum);
        dfs(root->right , sum , totalSum);

        if(!root->left and !root->right)
        totalSum += sum;

        sum /= 10;

        return ;
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum , totalSum;
        sum = totalSum = 0;

        dfs(root , sum , totalSum);

        return totalSum;
    }
};