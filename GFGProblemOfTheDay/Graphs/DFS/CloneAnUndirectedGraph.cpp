// Time Complexity : O(V + E)
// Space Complexity : O(V + E) + O(V) (for auxilary stack space)

// Problem Link : https://www.geeksforgeeks.org/problems/clone-graph/1

class Solution {
    private :
    Node* dfs(Node *node , map<Node* , Node*> &mp) {
        
        if(node == NULL) return NULL;
        
        if(mp.find(node) != mp.end()) return mp[node];
        
        Node *newNode = new Node(node->val);
        mp[node] = newNode;
        
        vector<Node*> adj = node->neighbors;
        
        for(int i = 0 ; i < adj.size() ; i++) {
            Node *neigh = dfs(adj[i] , mp);
            (newNode->neighbors).push_back(neigh);
        }
        
        return newNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        
        map<Node* , Node*> mp;
        
        return dfs(node , mp);
    }
};