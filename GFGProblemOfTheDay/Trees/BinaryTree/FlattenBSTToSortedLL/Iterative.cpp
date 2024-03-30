// Time Complexity : O(n)
// Space Complexity : O(n) (for stack data structure)

class Solution
{
    private :
    Node *head , *prevNode;
    
    void convertToLL(Node *root) {
        
        stack<Node*> st;
        
        while(!st.empty() or root != NULL) {
            
            while(root) {
                st.push(root);
                root = root->left;
            }
            
            Node *currNode = st.top();
            
            st.pop();
            
            if(head == NULL) {
                head = prevNode = currNode;
            }
            
            else {
                prevNode->left = NULL;
                prevNode->right = currNode;
                
                prevNode = currNode;
            }
            
            if(currNode->right) {
                root = currNode->right;
            }
        }
        
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