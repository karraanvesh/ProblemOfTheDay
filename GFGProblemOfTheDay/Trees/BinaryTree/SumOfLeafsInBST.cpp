// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1

class Solution
{
    
    public:
    /*You are required to complete below method */
    int sumOfLeafNodes(Node *root ){
         
        stack<Node*> st;
        int leafSum = 0;
         
        while(!st.empty() or root != NULL) {
             
            while(root) {
                st.push(root);
                root = root->left;
            }
             
            Node *currNode = st.top();
             
            st.pop();
             
            if(!currNode->left and !currNode->right) {
                leafSum += currNode->data;
            }
             
            if(currNode->right)
            root = currNode->right;
        }
         
         return leafSum;
    }
};