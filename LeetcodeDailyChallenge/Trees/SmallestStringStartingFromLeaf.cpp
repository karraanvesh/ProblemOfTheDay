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

// Time  Complexity : O(n + leaves * log(x))
// Space Complexity : O(paths)

// Problem Link : https://leetcode.com/problems/smallest-string-starting-from-leaf/?envType=daily-question&envId=2024-04-17

class Solution {
    private :
    void dfs(TreeNode *root , string &str , set<string> &st) {

        if(root == NULL) return ;

        char ch = 'a' + root->val;

        str += ch;

        dfs(root->left , str , st);
        dfs(root->right , str , st);

        if(!root->left and !root->right) {
            string curr = str;
            reverse(curr.begin() , curr.end());

            st.insert(curr);
        }

        str.pop_back();

        return ;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        set<string> st;

        string str;

        dfs(root , str , st);

        string result = *(st.begin());

        return result;
    }
};