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

// Time  Complexity : O(m*logm + n*logn)
// Space Complexity : O(m)
// where m are the nodes to be deleted

// Problem Link : https://leetcode.com/problems/delete-nodes-and-return-forest/?envType=daily-question&envId=2024-07-17

class Solution {
    private:
    void remainingTrees(TreeNode *root ,  TreeNode *par , vector<TreeNode*> &result , set<int> &st) {
        
        if(root == NULL) return ;
        
        remainingTrees(root->left , root , result , st);
        remainingTrees(root->right , root , result , st);
        
        int ele = root->val;
        
        if(st.count(ele) > 0) {
            TreeNode *leftChild , *rightChild;
            
            leftChild = root->left;
            rightChild = root->right;
            
            if(leftChild) {
                result.push_back(leftChild);
            }
            
            if(rightChild) {
                result.push_back(rightChild);
            }
            
            if(par) {
                
                if(root == par->left) {
                    par->left = NULL;
                }
                
                if(root == par->right) {
                    par->right = NULL;
                }

            }
            
        }
        
        return ;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        set<int> st;
        
        int m = to_delete.size();
        
        for(int i = 0 ; i < m ; i++)    {
            st.insert(to_delete[i]);
        }
        
        remainingTrees(root , NULL , result , st);
        
        int ele = root->val;
        
        if(st.count(ele) == 0) {
            result.push_back(root);
        }
        
        return result;
    }
};
