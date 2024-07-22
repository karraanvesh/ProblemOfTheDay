// Time  Complexity: O(n)
// Space Complexity: O(h) + O(n)
// where h is the height of the tree

// Problem Link : https://www.geeksforgeeks.org/problems/largest-bst/1

struct TreeNode {
    public :
    int noOfNodes;
    int maxElement;
    int minElement;
    
    TreeNode(int key , int maxi , int mini) {
        noOfNodes  = key;
        maxElement = maxi;
        minElement = mini;
    }
};

class Solution{
    private:
    TreeNode* f(Node *root , int &result) {
        
        TreeNode *newNode = NULL;
        
        if(!root) {
            newNode = new TreeNode(0 , INT_MIN , INT_MAX);
            return newNode;
        }
        
        TreeNode *leftNode , *rightNode;

        leftNode = f(root->left , result);
        rightNode = f(root->right , result);
        
        if(leftNode->maxElement < root->data and rightNode->minElement > root->data) {
            
            int noOfNodes = leftNode->noOfNodes + rightNode->noOfNodes + 1;
            result = max(result , noOfNodes);
            
            int currEle = root->data;
            int maxi = max({leftNode->maxElement , rightNode->maxElement , currEle});
            int mini = min({leftNode->minElement , rightNode->minElement , currEle});
            
            newNode = new TreeNode(noOfNodes , maxi , mini);
        }
        
        else {
            newNode = new TreeNode(0 , INT_MAX , INT_MIN);
        }
        
        return newNode;
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	int result = 0;
        
        TreeNode *node = f(root , result);
        
        return result;
    }
};
