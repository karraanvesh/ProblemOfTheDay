// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/level-order-traversal/1

class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* root)
    {
        vector<int> bfs;
        
        queue<pair<Node* , int>> q;
        q.push({root , 0});
        
        while(!q.empty()) {
            int currLevel = q.front().second;
            Node *currNode = q.front().first;
            
            q.pop();
            
            bfs.push_back(currNode->data);
            
            if(currNode->left)
            q.push({currNode->left , currLevel + 1});
            
            if(currNode->right)
            q.push({currNode->right , currLevel + 1});
        }
        
        return bfs;
    }
};