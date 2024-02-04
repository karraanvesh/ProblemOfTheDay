// Time  Complexity : O(n + m)
// Space Complexity : O(n + m)

// Problem Link : https://www.geeksforgeeks.org/problems/subtraction-in-linked-list/1

class Solution {
    private :
    int lengthOfLL(Node *head) {
        int ct = 0;
        Node *ptr = head;
        
        while(ptr != NULL) {
            ct++;
            ptr = ptr->next;
        }
        
        return ct;
    }
    Node* reverseList(Node *head) {
        if(head == NULL or head->next == NULL)
        return head;
        
        Node *prevNode , *currNode , *nextNode;
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
    int findLexico(Node *head1 , Node *head2) {
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        int listNo = -1;
        
        while(ptr1 != NULL and ptr2 != NULL) {
                
            if(ptr1->data > ptr2->data) {
                listNo = 1;
                break;
            }
            
            else if(ptr2->data > ptr1->data) {
                listNo = 2;
                break;
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return listNo;
    }
    Node* subtractLL(Node *head1 , Node *head2) {
        Node *ptr1 = head1 , *ptr2 = head2;
        
        ptr1 = reverseList(ptr1);
        ptr2 = reverseList(ptr2);
        
        Node *head , *ptr;
        head = ptr = NULL;
        
        while(ptr1 and ptr2) {
            
            if(ptr1->data >= ptr2->data) {
                int diff = ptr1->data - ptr2->data;
                
                Node *newNode = new Node(diff);
                
                if(head == NULL) {
                    ptr = head = newNode;
                } else {
                    ptr->next = newNode;
                    ptr = newNode;
                }
            }
            
            else {
                int ele = 10 + ptr1->data;
                
                if(ptr1->next) {
                    Node *nextNode = ptr1->next;
                    nextNode->data = nextNode->data - 1;
                }
                
                int diff = ele - ptr2->data;
                
                Node *newNode = new Node(diff);
                
                if(head == NULL) {
                    ptr = head = newNode;
                } else {
                    ptr->next = newNode;
                    ptr = newNode;
                }
            }
            
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1) {
            int ele;
            
            if(ptr1->data == -1) {
                ele = 9;
                Node *nextNode = ptr1->next;
                
                if(nextNode)
                nextNode->data = nextNode->data - 1;
            }
            
            else {
                ele = ptr1->data;
            }
            
            Node *newNode = new Node(ele);
                
            if(head == NULL) {
                ptr = head = newNode;
            } else {
                ptr->next = newNode;
                ptr = newNode;
            }
            
            ptr1 = ptr1->next;
        }
        
        head = reverseList(head);
        
        head = removeLeadingZeroes(head);
        
        return head;
    }
    Node* removeLeadingZeroes(Node *head) {
    
        if(head->next == NULL)
        return head;
        Node *ptr = head;
        
        while(ptr != NULL) {
            
            if(ptr->data != 0)
            break;
            
            ptr = ptr->next;
        }
        
        head = ptr;
        return head;
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        
        head1 = removeLeadingZeroes(head1);
        head2 = removeLeadingZeroes(head2);
        
        if(head1 == NULL and head2 == NULL) {
            return new Node(0);
        }
        
        if(head2 == NULL)
        return head1;
        
        if(head1 == NULL)
        return head2;
        
        int length1 = lengthOfLL(head1);
        int length2 = lengthOfLL(head2);
        Node *result;
        
        if(length1 > length2) 
        result = subtractLL(head1 , head2);
        
        else if(length2 > length1)
        result = subtractLL(head2 , head1);
        
        else {
            int listNo = findLexico(head1 , head2);
            
            if(listNo == 1)
            result = subtractLL(head1 , head2);
            
            else if(listNo == 2)
            result = subtractLL(head2 , head1);
            
            else
            return new Node(0);
        }
        
        return result;
    }
};