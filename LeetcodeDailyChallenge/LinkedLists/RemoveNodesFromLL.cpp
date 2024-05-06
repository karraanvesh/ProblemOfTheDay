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

// Problem Link : https://leetcode.com/problems/remove-nodes-from-linked-list/?envType=daily-question&envId=2024-05-06

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
    ListNode* removeNodes(ListNode* head) {
        
        if(head == NULL or head->next == NULL) return head;

        vector<int> arr;
        ListNode *ptr = head;

        while(ptr != NULL) {
            arr.push_back(ptr->val);
            ptr = ptr->next;
        }

        stack<int> st;
        int n = arr.size();

        for(int i = 0 ; i < n ; i++) {

            while(!st.empty() and arr[i] > arr[st.top()]) {
                st.pop();
            }

            st.push(i);
        }

        head = NULL;
        ListNode *prevNode = NULL;

        while(!st.empty()) {
            int ele = st.top();

            st.pop();

            ListNode *newNode = new ListNode(arr[ele]);

            if(head == NULL) {
                head = prevNode = newNode;
            }

            else {
                prevNode->next = newNode;
                prevNode = newNode;
            }
        }

        head = reverseList(head);

        return head;
    }
};