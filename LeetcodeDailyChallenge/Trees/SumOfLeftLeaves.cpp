// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/sum-of-left-leaves/description/?envType=daily-question&envId=2024-04-14

class Solution {
    private :
    void dfs(TreeNode *root , char ch , int &sum) {
        if(root == NULL) return ;

        if(!root->left and !root->right) {
            if(ch == 'L')
            sum += root->val;

            return ;
        }

        dfs(root->left , 'L' , sum);
        dfs(root->right , 'R' , sum);

        return ;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;

        dfs(root , 'N' , sum);

        return sum;
    }
};