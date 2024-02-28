// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28
 
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<int , TreeNode*>> q;
        q.push({0 , root});

        map<int , vector<int>> levelOrder;

        while(!q.empty()) {
            int currLevel = q.front().first;
            TreeNode *currNode = q.front().second;

            q.pop();

            levelOrder[currLevel].push_back(currNode->val);

            if(currNode->left)
            q.push({currLevel + 1 , currNode->left});

            if(currNode->right)
            q.push({currLevel + 1 , currNode->right});
        }

        map<int , vector<int>> :: iterator itr;

        itr = levelOrder.end();

        itr--;

        int result = levelOrder[itr->first][0];

        return result;
    }
};