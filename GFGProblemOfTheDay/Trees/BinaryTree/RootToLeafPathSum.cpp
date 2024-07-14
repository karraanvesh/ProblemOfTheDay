// Time  Complexity : O(n)
// Space Complexity : O(maximum_number_of_nodes_in_a_level)

// Problem Link : https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        int sum = 0;
        bool result = false;
        
        queue<pair<int , Node*>> q;
        
        q.push({root->data , root});
        
        while(!q.empty()) {
            int currSum = q.front().first;
            Node *currNode = q.front().second;
            
            q.pop();
            
            if(!currNode->left and !currNode->right) {
                
                if(currSum == target) {
                    result = true;
                    break;
                }
            }
            
            if(currNode->left) 
            q.push({currSum + currNode->left->data , currNode->left});
            
            if(currNode->right)
            q.push({currSum + currNode->right->data , currNode->right});
        }
        
        return result;
    }
};