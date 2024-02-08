// Time Complexity : O(n * logL)
// Space Complexity : O(L)
// where L are the number of leaf nodes 

// Problem Link : https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        if(root == NULL or (!root->left and !root->right))
        return true;
        
        queue<pair<Node* , int>> q;
        
        q.push({root , 1});
        set<int> st;
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int level = q.front().second;
            
            q.pop();
            
            if(!currNode->left and !currNode->right) {
                st.insert(level);
                continue;
            }
            
            if(currNode->left)
            q.push({currNode->left , level + 1});
            
            if(currNode->right)
            q.push({currNode->right , level + 1});
        }
        
        int noOfLevels = st.size();
        
        return (noOfLevels == 1);
    }
};