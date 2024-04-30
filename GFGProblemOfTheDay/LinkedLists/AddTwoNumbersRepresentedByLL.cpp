// Time  Complexity : O(n + m)
// Space Complexity : O(n + m)

// Problem Link : https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1

class Solution
{
    private :
    Node* reverseList(Node *head) {
        if(head == NULL or head->next == NULL) return head;
        
        Node *currNode , *prevNode , *nextNode;
        prevNode = nextNode = NULL;
        currNode = head;
        
        while(currNode != NULL) {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* head1, struct Node* head2)
    {
        if(head1 == NULL) return head2;
        
        if(head2 == NULL) return head1;
        
        // 1 . eliminate leading zeroes in both the numbers 
        
        while(head1 != NULL and head1->data == 0) {
            head1 = head1->next;
        }
        
        while(head2 != NULL and head2->data == 0) {
            head2 = head2->next;
        }
        
        if(!head1 and !head2) return new Node(0);
        
        if(head1 == NULL) return head2;
        
        if(head2 == NULL) return head1;
        
        
        // 2. reverse both the lists 
        
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        
        Node *ptr1 , *ptr2;
        ptr1 = head1;
        ptr2 = head2;
        
        Node *head , *prevNode;
        head = prevNode = NULL;
        int carry = 0;
        
        
        while(ptr1 != NULL and ptr2 != NULL) {
            int sum = ptr1->data + ptr2->data + carry;
            
            Node *newNode = new Node(sum%10);
            
            if(head == NULL) {
                head = prevNode = newNode;
            }
            
            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }
            
            carry = sum / 10;
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1 != NULL) {
            int sum = ptr1->data + carry;
            
            Node *newNode = new Node(sum%10);
            
            if(head == NULL) {
                head = prevNode = newNode;
            }
            
            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }
            
            carry = sum / 10;
            
            ptr1 = ptr1->next;
        }
        
        while(ptr2 != NULL) {
            int sum = ptr2->data + carry;
            
            Node *newNode = new Node(sum%10);
            
            if(head == NULL) {
                head = prevNode = newNode;
            }
            
            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }
            
            carry = sum / 10;
            
            ptr2 = ptr2->next;
        }
        
        while(carry > 0) {
            int sum = carry;
            
            Node *newNode = new Node(sum%10);
            
            if(head == NULL) {
                head = prevNode = newNode;
            }
            
            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }
            
            carry /= 10;
        }
        
        head = reverseList(head);
        
        return head;
        
    }
};