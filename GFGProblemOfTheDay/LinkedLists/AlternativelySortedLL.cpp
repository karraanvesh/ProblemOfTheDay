// Time  Complexity : O(n * logn)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

class Solution
{
    private :
    Node* mergeLists(Node *head1 , Node *head2) {
        if(head1 == NULL) return head2;
        
        if(head2 == NULL) return head1;
        
        Node *nextNode = NULL;
        
        if(head1->data <= head2->data) {
           head1->next = mergeLists(head1->next , head2);
           
           return head1;
        }
        
        else {
           head2->next = mergeLists(head1 , head2->next);
           
           return head2;
        }
    }
    
    Node* mergeSort(Node *head) {
        if(head == NULL or head->next == NULL) return head;
        
        Node *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = head->next;
        
        while(fastPtr != NULL and fastPtr->next != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        Node *l1 = head , *l2 = slowPtr->next;
        
        slowPtr->next = NULL;
        
        l1 = mergeSort(l1);
        l2 = mergeSort(l2);
        
        return mergeLists(l1 , l2);
    }
    public:
    // your task is to complete this function
    void sort(Node **head_ref)
    {
        Node *head = *head_ref;
        
        head = mergeSort(head);
        
        return ;
    }
};