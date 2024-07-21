/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return the root of the modified tree after removing all the half nodes.

// Time  Complexity : O(n)
// Space Complexity : O(h)
// where h is the height of the binary tree 

// Problem Link : https://www.geeksforgeeks.org/problems/remove-half-nodes/1

class Solution {
    private:
    bool isHalf(Node *root) {
        
        return ((root->left and !root->right) or (!root->left and root->right));
    }
    
    void f(Node *root , Node *par) {
        
        if(!root) return ;
        
        if(isHalf(root)) {
            
            Node *temp = root;
            
            while(root and isHalf(root)) {
                
                if(root->left) {
                    root = root->left;
                }
                
                else {
                    root = root->right;
                }
            }
            
            if(root and temp == par->left)
            par->left = root;
            
            if(root and temp == par->right)
            par->right = root;
        }
        
        if(root) {
            
            f(root->left , root);
            f(root->right , root);
        }
        
        return ;
    }
  public:
    Node *RemoveHalfNodes(Node *root) {
        
        while(root and isHalf(root)) {
            
            if(root->left) {
                root = root->left;
            }
            
            else {
                root = root->right;
            }
        }
        
        f(root , NULL);
        
        return root;
    }
};
