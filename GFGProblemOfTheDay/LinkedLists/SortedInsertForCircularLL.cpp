// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1

class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
       if(head == NULL) {
           Node *newNode = new Node(data);
           newNode->next = newNode;
           head = newNode;
           
           return head;
       }
       
       if(head->next == head) {
           // single node in cll
           Node *newNode = new Node(data);
           if(newNode->data < head->data) {
               newNode->next = head;
               head->next = newNode;
               head = newNode;
           }
           
           else {
               head->next = newNode;
               newNode->next = head;
           }
           
           return head;
       }
       
       // multiple nodes 
       
      
       
       Node *newNode = new Node(data);
       Node *ptr = head;
       
       if(newNode->data < head->data) {
           newNode->next = head;
           Node *ptr = head;
           
           while(ptr->next != head) {
               ptr = ptr->next;
           }
           
           ptr->next = newNode;
           head = newNode;
       }
       
       else {
            
            Node *prevNode = NULL;
            ptr = head;
            
            while(ptr->next != head) {
               if(newNode->data < ptr->data) {
                   prevNode->next = newNode;
                   newNode->next = ptr;
                   return head;
               }
               
               prevNode = ptr;
               ptr = ptr->next;
            } 
            
            if(newNode->data < ptr->data) {
               prevNode->next = newNode;
               newNode->next = ptr;
           }
           else {
               ptr->next = newNode;
               newNode->next = head;
           }

       }
       
       return head;
    }
};