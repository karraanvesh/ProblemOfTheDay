// Time Complexity : O(n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

class Solution
{
    private :
    Node *head , *prevNode;
    void convertToLL(Node *root) {
        
        if(root == NULL) return ;
        
        convertToLL(root->left);
        
        if(head == NULL) {
            head = prevNode = root;
        }
        
        else {
            prevNode->left = NULL;
            prevNode->right = root;
            
            prevNode = root;
        }
        
        convertToLL(root->right);
        
        return ;
    }
public:
    Node *flattenBST(Node *root)
    {
        if(root == NULL or (!root->left and !root->right))
        return root;
        
        head = prevNode = NULL;
        
        convertToLL(root);
        
        prevNode->left = prevNode->right = NULL;
        
        return head;
    }
};