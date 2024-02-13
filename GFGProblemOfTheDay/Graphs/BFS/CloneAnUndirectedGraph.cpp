// Time Complexity : O(V + E)
// Space Complexity : O(V + E) + O(V)

// Problem Link : https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
    private :
    Node* bfs(Node *node , map<Node* , Node*> &mp) {
        queue<Node*> q;
        
        q.push(node);
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        
        while(!q.empty()) {
            Node *currNode = q.front();
            
            q.pop();
            
            Node *newNode = mp[currNode];
           
            vector<Node*> adj = currNode->neighbors;
            
            
            for(int i = 0 ; i < adj.size() ; i++) {
                Node *neigh = adj[i];
                
                if(mp.find(neigh) != mp.end()) {
                    (newNode->neighbors).push_back(mp[neigh]);
                }
                
                else {
                    Node *newNeigh = new Node(neigh->val);
                    mp[neigh] = newNeigh;
                    
                    (newNode->neighbors).push_back(mp[neigh]);
                    
                    q.push(neigh);
                }
            }
        }
        
        return mp[node];
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        map<Node* , Node*> mp;
        
        return bfs(node , mp);
    }
};