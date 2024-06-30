// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        
        // delete at first
        if(x == 1) {
            Node *node = head;
            
            head = head->next;
            head->prev = NULL;
            
            delete node;
            
            return head;
        }
        
        Node *prevNode , *currNode;
        prevNode = NULL;
        currNode = head;
        
        int ct = 1;
        
        while(currNode != NULL) {
            
            if(ct == x)
            break;
            
            prevNode = currNode;
            currNode = currNode->next;
            
            ct++;
        }
        
        // delete at the end
        if(currNode->next == NULL) {
            prevNode->next = NULL;
            
            delete currNode;
            
            return head;
        }
        
        // delete at middle 
        prevNode->next = currNode->next;
        currNode->next->prev = prevNode;
        
        delete currNode;
        
        return head;
    }
};