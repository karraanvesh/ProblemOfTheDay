// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	vector<int> result;
    	
    	deque<Node*> dq1 , dq2;
    	
    	dq1.push_back(root);
    	
    	while(!dq1.empty() or !dq2.empty()) {
    	    
    	    if(!dq1.empty()) {
    	        
    	        while(!dq1.empty()) {
    	            Node *currNode = dq1.front();
    	            
    	            dq1.pop_front();
    	            
    	            result.push_back(currNode->data);
    	            
    	            if(currNode->left)
    	            dq2.push_back(currNode->left);
    	            
    	            if(currNode->right)
    	            dq2.push_back(currNode->right);
    	        }
    	    }
    	    
    	    else {
                while(!dq2.empty()) {
    	            Node *currNode = dq2.back();
    	            
    	            dq2.pop_back();
    	            
    	            result.push_back(currNode->data);
    	            
    	            if(currNode->right)
    	            dq1.push_front(currNode->right);
    	            
    	            if(currNode->left)
    	            dq1.push_front(currNode->left);
    	        }
    	    }
    	}
    	
    	return result;
    }
};