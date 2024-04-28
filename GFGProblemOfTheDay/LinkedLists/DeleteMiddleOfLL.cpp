// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        if(head->next == NULL) {
            head = NULL;
            return head;
        }
        
        Node *slowPtr , *fastPtr , *prevNode;
        slowPtr = head;
        fastPtr = head->next;
        prevNode = NULL;
        
        while(fastPtr != NULL and fastPtr->next != NULL) {
            prevNode = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        if(fastPtr == NULL) {
            prevNode->next = slowPtr->next;
            delete slowPtr;
        }
        
        else {
            slowPtr->next = slowPtr->next->next;
        }
        
        return head;
        
    }
};