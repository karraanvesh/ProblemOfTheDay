// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1

class Solution {
public:   
    int minValue(Node* root) {
        int result = root->data;
        
        while(root->left != NULL) {
            root = root->left;
            
            result = root->data;
        }
        
        return result;
    }
};