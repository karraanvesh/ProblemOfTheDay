// Time Complexity  : O(n)
// Space Complexity : O(n)
// where n are the number of elements in a queue 

// Problem Link : https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

class MyQueue {
    private :
    stack<int> st1 , st2;
public:
    MyQueue() {
        
        while(!st1.empty()) {
            st1.pop();
        }

        while(!st2.empty()) {
            st2.pop();
        }
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int ele = st2.top();
        st2.pop();

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }
    
    int peek() {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        int ele = st2.top();

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }

        return ele;
    }
    
    bool empty() {
        if(st1.empty()) return true;

        return false;
    }
};