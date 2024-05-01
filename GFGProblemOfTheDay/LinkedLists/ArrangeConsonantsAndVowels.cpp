// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/arrange-consonants-and-vowels/1

class Solution
{
    private :
    bool isVowel(char ch) {
        return (ch  == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u');
    }
    public:
    // task is to complete this function
    // function should return head to the list after making 
    // necessary arrangements
    struct Node* arrangeCV(Node *head)
    {
       if(head == NULL or head->next == NULL) return head;
       
       Node *h1 , *h2 , *prevNode1 , *prevNode2;
       h1 = h2 = NULL;
       prevNode1 = prevNode2 = NULL;
       
       Node *ptr = head;
       
       while(ptr != NULL) {
           
           char ch = ptr->data;
        
           if(isVowel(ch)) {
               
               if(h1 == NULL) {
                   prevNode1 = h1 = ptr;
               }
               
               else {
                   prevNode1->next = ptr;
                   prevNode1 = ptr;
               }
           }
           
           else {
               
               if(h2 == NULL) {
                   prevNode2 = h2 = ptr;
               }
               
               else {
                   prevNode2->next = ptr;
                   prevNode2 = ptr;
               }
           }
           
           ptr = ptr->next;
       }
       
       if(h1 == NULL) {
           prevNode2->next = NULL;
           return h2;
       }
       
       if(h2 == NULL) {
           prevNode1->next = NULL;
           return h1;
       }
       
       prevNode1->next = h2;
       prevNode2->next = NULL;
       
       return h1;
    }
};