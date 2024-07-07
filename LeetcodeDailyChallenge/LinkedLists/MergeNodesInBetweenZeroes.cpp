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

// Time Complexity: O(n)
// Space Complexity: O(number_of_zeroes_in_LL - 1)

// Problem Link : https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
       ListNode *ptr = head;
        
        ListNode *newHead , *prevNode;
        
        newHead = prevNode = NULL;
        
        ptr = ptr->next;
        int sum = 0;
        
        while(ptr != NULL) {
            
            sum += ptr->val;
            
            if(ptr->val == 0) {
                
                ListNode *newNode = new ListNode(sum);
                
                if(newHead == NULL)           {
                    prevNode = newHead = newNode;
                }
                
                else {
                    prevNode->next = newNode;
                    prevNode = newNode;
                }
                
                sum = 0;
            }
            
            ptr = ptr->next;
        }
        
        return newHead;
    }
};