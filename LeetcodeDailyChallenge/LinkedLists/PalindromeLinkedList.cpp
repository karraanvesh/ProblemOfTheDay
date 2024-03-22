// Time  Complexity : O(n)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-22

class Solution {
    private :
    ListNode* reverseList(ListNode *head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode *currNode , *prevNode , *nextNode;
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

    bool compareLists(ListNode *head1 , ListNode *head2) {
        ListNode *ptr1 , *ptr2;
        ptr1 = head1;
        ptr2 = head2;

        while(ptr1 != NULL and ptr2 != NULL) {
            if(ptr1->val != ptr2->val)
            return false;

            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if(ptr1 == NULL and ptr2 == NULL)
        return true;

        return false;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL or head->next == NULL)
        return true;

        ListNode *slowPtr , *fastPtr;
        slowPtr = head;
        fastPtr = slowPtr->next;
        ListNode *prevNode = NULL;

        while(fastPtr != NULL and fastPtr->next != NULL) {
            prevNode = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        ListNode *list1 , *list2;

        if(fastPtr == NULL) {
            prevNode->next = NULL;
            list2 = slowPtr->next;
            list1 = head;
        }

        else {
            list1 = head;
            list2 = slowPtr->next;
            slowPtr->next = NULL;
        }

        list2 = reverseList(list2);

        return compareLists(list1 , list2);
    }
};