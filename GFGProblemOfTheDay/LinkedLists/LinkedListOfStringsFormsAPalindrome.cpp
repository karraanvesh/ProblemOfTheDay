// Time Complexity: O(n + length_of_str)
// Space Complexity: O(length_of_str)

// Problem Link : https://www.geeksforgeeks.org/problems/linked-list-of-strings-forms-a-palindrome/1

class Solution {
    private: 
    bool isPalindrome(string &str) {
        int n = str.length();
        int left = 0 , right = n-1;
        
        while(left < right) {
            
            if(str[left] != str[right]) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
  public:
    bool compute(Node* head) {
        Node *ptr = head;
        string str;
        
        while(ptr != NULL) {
            str += ptr->data;
            ptr = ptr->next;
        }
        
        return isPalindrome(str);
        
    }
};