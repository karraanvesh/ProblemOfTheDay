// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       del_node->data = del_node->next->data;
       del_node->next = del_node->next->next;
       
       return ;
    }

};