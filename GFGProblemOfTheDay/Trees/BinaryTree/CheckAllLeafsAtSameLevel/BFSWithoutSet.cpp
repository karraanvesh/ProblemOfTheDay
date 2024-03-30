// Time  Complexity : O(n)
// Space Complexity : O(n)

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        if(root == NULL or (!root->left and !root->right))
        return true;
        
        queue<pair<Node* , int>> q;
        
        q.push({root , 1});
        int leafLevel = -1;
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            if(!currNode->left and !currNode->right) {
                if(leafLevel == -1) {
                    leafLevel = level;
                }
                
                else if(leafLevel != level) {
                    return false;
                }
                continue;
            }
            
            if(currNode->left)
            q.push({currNode->left , level + 1});
            
            if(currNode->right)
            q.push({currNode->right , level + 1});
        }
        
        return true;
    }
};