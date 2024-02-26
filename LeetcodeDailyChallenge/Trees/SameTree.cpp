// Time  Complexity : O(n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/same-tree/description/?envType=daily-question&envId=2024-02-26
 
class Solution {
    private :
    bool isIdentical(TreeNode *root1 , TreeNode *root2) {

        if(root1 == NULL and root2 == NULL) return true;

        if(root1 and !root2) return false;

        if(!root1 and root2) return false;

        if(root1->val == root2->val) {
            return isIdentical(root1->left , root2->left) and isIdentical(root1->right , root2->right);
        }

        return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL) return true;

        if(p and !q) return false;

        if(!p and q) return false;

        return isIdentical(p , q);
    }
};