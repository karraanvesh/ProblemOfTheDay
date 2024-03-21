// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	map<int , vector<int>> levelOrder;
    	queue<pair<int , Node*>> q;
    	q.push({1 , root});
    	
    	while(!q.empty()) {
    	    int currLevel = q.front().first;
    	    Node *currNode = q.front().second;
    	    
    	    q.pop();
    	    
    	    levelOrder[currLevel].push_back(currNode->data);
    	    
    	    if(currNode->left)
    	    q.push({currLevel + 1 , currNode->left});
    	    
    	    if(currNode->right)
    	    q.push({currLevel + 1 , currNode->right});
    	}
    	
    	map<int , vector<int>> :: iterator itr;
    	vector<int> result;
    	
    	for(itr = levelOrder.begin() ; itr != levelOrder.end() ; itr++) {
    	    int level = itr->first;
    	    vector<int> nodes;
    	    nodes = itr->second;
    	    
    	    if(level%2 == 0)
    	    reverse(nodes.begin() , nodes.end());
    	    
    	    int n = nodes.size();
    	    
    	    for(int i = 0 ; i < n ; i++) {
    	        result.push_back(nodes[i]);
    	    }
    	}
    	
    	return result;
    }
};