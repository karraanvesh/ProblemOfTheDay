 // Time Complexity  : O(n)
 // Space Complexity : O(h) ( for auxilary stack space)
 // where h is the height of the given tree 

 // Problem Link : https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24
 
class Solution {
    private:
    int palindromicPathsCount;

    bool checkPalindrome(vector<int> &mp) {

        int oddFreq = 0;
        for(int i = 1 ; i <= 9 ; i++) {

            if(mp[i] and mp[i]%2 == 1)
            oddFreq++;
        }

        return (oddFreq == 0 or oddFreq == 1);
    }

    void dfs(TreeNode *root , vector<int> &mp) {

        if(!root) return ;

        int ele = root->val;
        mp[ele]++;

        dfs(root->left , mp);
        dfs(root->right , mp);

        if(!root->left and !root->right) {
            bool b = checkPalindrome(mp);
            
            if(b)
            palindromicPathsCount++;
        }

        mp[ele]--;

        return ;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        palindromicPathsCount = 0;
        vector<int> mp(11 , 0);

        dfs(root , mp);

        return palindromicPathsCount;
    }
};