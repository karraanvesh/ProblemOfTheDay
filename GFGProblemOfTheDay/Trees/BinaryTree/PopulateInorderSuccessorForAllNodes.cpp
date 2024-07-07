// Time  Complexity : O(n)
// Space Complexity : O(h) ~ O(n) (If we are given a skewed binary tree )
// where h is the height of the binary tree 

// Problem Link : https://www.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

class Solution {
  public:

    void populateNext(Node *root) {
        
        if(root == NULL or (!root->left and !root->right))
        return ;
        
        stack<Node*> st;
        Node *currNode = root , *prevNode = NULL;
        
        while(!st.empty() or currNode != NULL) {
            
            while(currNode != NULL) {
                st.push(currNode);
                currNode = currNode->left;
            }
            
            Node *node = st.top();
            st.pop();
            
            if(prevNode != NULL) {
                prevNode->next = node;
            }
            
            prevNode = node;
            
            if(node->right)
            currNode = node->right;
        }
        
        return ;
    }
};