// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

class Solution {
  public:
    int findMaxForN(Node* root, int n) {
        int result = -1;
        Node *ptr = root;
        
        while(ptr != NULL) {
            
            if(ptr->key <= n) {
                result = ptr->key;
                ptr = ptr->right;
            }
            
            else {
                ptr = ptr->left;
            }
        }
        
        return result;
    }
};