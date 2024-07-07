// Time  Complexity: O(n * logn)
// Space Complexity: O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/make-binary-tree/1

// Function to make binary tree from linked list.
void convert(Node *head, TreeNode *&root) {
    vector<int> arr;
    
    Node *ptr = head;
    
    while(ptr != NULL) {
        arr.push_back(ptr->data);
        ptr = ptr->next;
    }
    
    int n = arr.size();
    
    map<int , TreeNode*> mp;
    
    TreeNode *newNode = new TreeNode(arr[0]);
    root = newNode;
    
    mp.insert({0 , newNode});
    
    for(int i = 0 ; i < n/2 ; i++) {
        
        int leftChild = 2*i + 1;
        int rightChild = 2*i + 2;
        
        TreeNode *currNode = mp[i];
        
        if(leftChild < n) {
            TreeNode *newNode = new TreeNode(arr[leftChild]);
            currNode->left = newNode;
            
            mp.insert({leftChild , newNode});
        }
        
        if(rightChild < n) {
            TreeNode *newNode = new TreeNode(arr[rightChild]);
            currNode->right = newNode;
            
            mp.insert({rightChild , newNode});
            
        }
    }
    
    return ;
}