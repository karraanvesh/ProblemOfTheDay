// Time  Complexity : O(n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://leetcode.com/problems/diameter-of-binary-tree/description/?envType=daily-question&envId=2024-02-27
 
class Solution {
    private :
    int result;
    int findDiameter(TreeNode *root) {
        if(root == NULL) return 0;

        if(!root->left and !root->right) return 0;

        int diameter = 0;
        int leftHt , rightHt;
        leftHt = rightHt = 0;

        if(root->left and root->right) {
            diameter = 2;

            leftHt = findDiameter(root->left);
            rightHt = findDiameter(root->right);

            diameter += leftHt + rightHt;
            result = max(result , diameter);
        }

        else if(root->left) {
            diameter = 1;

            leftHt = findDiameter(root->left);

            diameter += leftHt;

            result = max(result , diameter);
        }

        else {
            diameter = 1;

            rightHt = findDiameter(root->right);

            diameter += rightHt;

            result = max(result , diameter);
        }

        return max(rightHt , leftHt) + 1;

    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL or (!root->left and !root->right))
        return 0;

        result = 0;

        int x = findDiameter(root);

        return result;
    }
};