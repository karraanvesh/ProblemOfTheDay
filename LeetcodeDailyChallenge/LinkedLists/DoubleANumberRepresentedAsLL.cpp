/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Time  Complexity : O(n)
// Space Complexity : O(n)

// Problem Link : https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

class Solution {
    private :
    ListNode* reverseList(ListNode *head) {
        if(head == NULL or head->next == NULL) return head;

        ListNode *prevNode , *nextNode , *currNode;
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
    ListNode* doubleIt(ListNode* head) {
        if(head == NULL) return head;

        head = reverseList(head);

        ListNode *ptr = head;
        int carry = 0;
        ListNode *h1 , *prevNode;
        h1 = prevNode = NULL;

        while(ptr != NULL) {
            int ele = carry + (ptr->val * 2);

            ListNode *newNode = new ListNode(ele%10);

            if(h1 == NULL) {
                h1 = prevNode = newNode;
            }

            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }

            carry = ele / 10;
            ptr = ptr->next;
        }

        while(carry) {
            int ele = carry ;

            ListNode *newNode = new ListNode(ele%10);

            if(h1 == NULL) {
                h1 = prevNode = newNode;
            }

            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }

            carry = carry / 10;
        }

        h1 = reverseList(h1);

        return h1;
    }
};