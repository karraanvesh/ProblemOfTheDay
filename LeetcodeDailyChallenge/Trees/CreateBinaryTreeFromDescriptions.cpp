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

// Time  Complexity : O(n * logn)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/create-binary-tree-from-descriptions/description/?envType=daily-question&envId=2024-07-15

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int m = descriptions.size();
        
        map<int , TreeNode*> mp;
        set<TreeNode*> st;
        
        for(int i = 0 ; i < m ; i++)    {
            int parent = descriptions[i][0];
            int child = descriptions[i][1];
            int isLeft = descriptions[i][2];
            
            TreeNode *node1 , *node2;
            
            node1 = (mp.find(parent) != mp.end()) ? mp[parent] : new TreeNode(parent);
            
            node2 = (mp.find(child) != mp.end()) ? mp[child] : new TreeNode(child);
            
            if(isLeft)
            node1->left = node2;
            
            else
            node1->right = node2;
            
            st.insert(node2);
            
            if(mp.find(parent) == mp.end())
            mp.insert({parent , node1});
            
            if(mp.find(child) == mp.end())
            mp.insert({child , node2});
        }
        
        TreeNode *root = NULL;
        
        map<int , TreeNode*> :: iterator itr;
        
        for(itr = mp.begin() ; itr != mp.end() ; itr++) {
            TreeNode *node = mp[itr->first];
            
            if(st.count(node) == 0) {
                root = node;
                break;
            }
        }
        
        return root;
    }
};
