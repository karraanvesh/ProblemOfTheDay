// Time  Complexity : O(n * logn)
// Space Complexity : O(logn)

// Problem Link : https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1

class Solution
{
    private :
    long mod = 1e9 + 7;
    long long power(long a , long b) {
        
        if(b == 0) return 1;
        
        if(b == 1) return 2;
        
        long long x = power(a , b/2);
        
        if(b%2 == 0) {
            return (x%mod * x%mod)%mod;
        }
        
        return (x%mod * x%mod * 2%mod)%mod;
    }
    Node* reverseList(Node *head) {
        if(head == NULL or head->next == NULL)
        return head;
        
        Node *prevNode , *nextNode , *currNode;
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
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           long long unsigned int result = 0;
           
           head = reverseList(head);
           
           Node *ptr = head;
           int p = 0;
           
           while(ptr != NULL) {
               
               if(ptr->data) {
                   long long unsigned int num = power(2 , p);
                   result = (result%mod + num%mod)%mod;
               }
               ptr = ptr->next;
               p++;
           }
           
           return result;
        }
};