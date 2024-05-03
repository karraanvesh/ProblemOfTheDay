// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/k-distance-from-root/1

class Solution
{
    public:
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
        vector<int> result;
        
        queue<pair<Node* , int>> q;
        q.push({root , k});
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            if(level == 0)
            result.push_back(currNode->data);
            
            if(currNode->left and level) {
                q.push({currNode->left , level - 1});
            }
            
            if(currNode->right and level) {
                q.push({currNode->right , level - 1});
            }
        }
        
        return result;
    }
};