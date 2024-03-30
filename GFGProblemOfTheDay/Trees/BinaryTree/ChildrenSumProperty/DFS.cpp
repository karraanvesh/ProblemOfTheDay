// Time  Complexity : O(n)
// Space Complexity : O(n) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/children-sum-parent/1

class Solution{
    private :
    int result;
    
    int isValid(Node *root) {
        
        if(root == NULL) return 0;
        
        if(!root->left and !root->right) return root->data;
        
        int leftChildVal = isValid(root->left);
        int rightChildVal = isValid(root->right);
        int sum = leftChildVal + rightChildVal;
        
        int currData = root->data;
        
        if(sum != currData)
        result = 0;
        
        return currData;
    }
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int isSumProperty(Node *root)
    {
        if(root == NULL or (!root->left and !root->right)) return 1;
    
        result = 1;
        
        int x = isValid(root);
        
        return result;
    }
};