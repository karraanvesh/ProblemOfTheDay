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
// Space Complexity : O(h)
// where h is the height of the BST 

// Problem Link : https://leetcode.com/problems/balance-a-binary-search-tree/description/?envType=daily-question&envId=2024-06-26

class Solution {
    private :
    void inorder (TreeNode* root , vector<int> &arr) {

        stack<TreeNode*> st;
        TreeNode *currNode = root;

        while(!st.empty() or currNode != NULL) {

            while(currNode != NULL) {
                st.push(currNode);
                currNode = currNode->left;
            }

            TreeNode *node = st.top();
            st.pop();

            arr.push_back(node->val);

            if(node->right)
            currNode = node->right;
        }

        return ;
    }
    TreeNode* buildBST(vector<int> &arr , int low , int high) {
        
        if(low > high) return NULL;
        
        int mid = low + (high - low)/2;

        TreeNode *newNode = new TreeNode(arr[mid]);
        
        newNode->left = buildBST(arr , low , mid - 1);
        newNode->right = buildBST(arr , mid + 1 , high);
        
        return newNode;
    }
    int f(TreeNode *root , bool &isBalanced) {
        
        if(!root) return 0;
        
        int leftSubHt = f(root->left , isBalanced);
        int rightSubHt = f(root->right , isBalanced);
        
        int diff = abs(leftSubHt - rightSubHt);
        
        if(diff > 1)
        isBalanced = false;
        
        return max(rightSubHt , leftSubHt) + 1;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        if(!root->left and !root->right) return root;
        
        bool isBalanced = true;
        int x = f(root , isBalanced);
        
        if(isBalanced) return root;
        
        vector<int> arr;
        inorder(root , arr);
        
        return buildBST(arr , 0 , arr.size() - 1);
    }
};