// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/remove-every-kth-node/1

class Solution {
    public:
    Node* deleteK(Node *head,int K){
        if(head == NULL) return head;
        
        if(K == 1) return NULL;
        
        Node *currNode = head , *prevNode = NULL;
        int ct = 0;
        
        while(currNode != NULL) {
            ct++;
            
            if(ct%K == 0) {
                prevNode->next = currNode->next;
            }
            
            prevNode = currNode;
            currNode = currNode->next;
        }
        
        return head;
    }
};