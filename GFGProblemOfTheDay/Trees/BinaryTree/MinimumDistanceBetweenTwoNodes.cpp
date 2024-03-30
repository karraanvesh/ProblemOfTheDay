// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

class Solution{
    private :
    Node *lca;
    int findLCA(Node *root , Node *parent , map<Node* , Node*> &mp , int a , int b , queue<pair<Node* , int>> &q) {
        
        if(root == NULL) return 0;
        
        mp[root] = parent;
        
        int leftSTCount = findLCA(root->left , root , mp , a , b , q );
        int rightSTCount = findLCA(root->right , root , mp , a , b , q);
        
        int ele = root->data;
        int currCount = (ele == a) or (ele == b);
        
        int totalCount = leftSTCount + rightSTCount + currCount;
        
        if(totalCount >= 2 and !lca) {
            lca = root;
        }
        
        if(currCount) {
            q.push({root , 0});
        }
        
        return totalCount;
    }
    int bfs(queue<pair<Node* , int>> &q , map<Node* , Node*> &mp) {
        
        int minDistance = 0;
        
        while(!q.empty()) {
            Node *currNode = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            Node *par = mp[currNode];
            
            if(par == NULL) {
                minDistance += dist;
                continue;
            }
            
            q.push({par , dist + 1});
        }
        
        return minDistance;
    }
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        if(root == NULL) return 0;
        
        if(a == b) return 0;
        
        map<Node* , Node*> mp;
        lca = NULL;
        queue<pair<Node* , int>> q;
        int x = findLCA(root , NULL , mp , a , b , q);
        
        mp[lca] = NULL;
        
        int result = bfs(q , mp);
        
        return result;
    }
};