// Time  Complexity : O(n)
// Space Complexity : O(n)

class Solution
{
    private :
    void bfs(Node *root , Node *parent , int k , queue<pair<Node* , int>> &q , map<Node* , Node*> &mp) {
        
        queue<pair<Node* , Node*>> levelOrder;
        
        levelOrder.push({root , parent});
        
        while(!levelOrder.empty()) {
            Node *currNode = levelOrder.front().first;
            Node *par = levelOrder.front().second;
            
            levelOrder.pop();
            
            mp[currNode] = par;
            
            if(currNode->left)
            levelOrder.push({currNode->left , currNode});
            
            if(currNode->right)
            levelOrder.push({currNode->right , currNode});
            
            else if(!currNode->left and !currNode->right) {
                q.push({currNode , k});
            }
        }
        
        return ;
    }
    public:
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k)
    {
    	if(root == NULL or (!root->left and !root->right)) return 0;
    	
    	queue<pair<Node* , int>> q;
    	map<Node* , Node*> mp;
    	
    	bfs(root , NULL , k , q , mp);
    	
    	set<Node*> st;
    	
    	while(!q.empty()) {
    	    Node *currNode = q.front().first;
    	    int dist = q.front().second;
    	    
    	    q.pop();
    	    
    	    if(dist == 0) {
    	        st.insert(currNode);
    	        continue;
    	    }
    	    
    	    if(mp[currNode]) {
    	        q.push({mp[currNode] , dist - 1});
    	    }
    	}
    	
    	int specialNodeCount = st.size();
    	
    	return specialNodeCount;
    }
};