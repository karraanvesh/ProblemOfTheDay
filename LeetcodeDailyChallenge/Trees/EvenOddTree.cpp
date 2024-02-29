// Time  Complexity : O(n)
// Space Complexity : O(n) 

// Problem Link : https://leetcode.com/problems/even-odd-tree/?envType=daily-question&envId=2024-02-29

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(!root) return true;

        map<int , vector<int>> levelOrder;
        queue<pair<int , TreeNode*>> q;
        q.push({0 , root});

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

        for(itr = levelOrder.begin() ; itr != levelOrder.end() ; itr++) {
            int level = itr->first;
            vector<int> nodes = itr->second;
            int n = nodes.size();

            if(n == 1) {
                if(level%2 == 0 and nodes[0]%2 == 0)
                return false;

                if(level%2 == 1 and nodes[0]%2 == 1)
                return false;
            }

            for(int i = 1 ; i < n ; i++) {
                if(level%2 == 0) {
                    if(nodes[i] <= nodes[i-1] or nodes[i]%2 == 0 or nodes[i-1]%2 == 0)
                    return false;
                }
                else {
                    if(nodes[i] >= nodes[i-1] or nodes[i]%2 == 1 or nodes[i-1]%2 == 1)
                    return false;
                }
            }
        }

        return true;
    }
};