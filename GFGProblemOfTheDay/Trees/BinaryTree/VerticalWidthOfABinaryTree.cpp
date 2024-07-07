// Time  Complexity: O(n * logn)
// Space Complexity : O(number_of_vertical_lines)

// Problem Link : https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

class Solution {
  public:
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        
        if(root == NULL)
        return 0;
        
        set<int> verticalLines;
        queue<pair<Node* , int>> q;
        
        q.push({root , 0});
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int currVL = q.front().second;
            
            q.pop();
            
            verticalLines.insert(currVL);
            
            if(currNode->left)
            q.push({currNode->left , currVL - 1});
            
            if(currNode->right)
            q.push({currNode->right , currVL + 1});
        }
        
        int result = verticalLines.size();
        
        return result;
    }
};