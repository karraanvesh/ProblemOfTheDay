// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        stack<int> st;
        deque<int> dq;
        
        for(int i = n - 1 ; i >= 0 ; i--)  {
            st.push(sandwiches[i]);
            dq.push_back(students[n-i-1]);
        }
        
        set<deque<int>> mp;
        
        mp.insert(dq);
        
        while(!st.empty()) {
            int currSW = st.top();
            int studReq = dq.front();
            
            dq.pop_front();
            
            if(currSW == studReq) {
                st.pop();
            }
            
            else { 
                dq.push_back(studReq);
            }
            
            n = n;
            
            if(mp.count(dq) == 0) {
                mp.insert(dq);
            }
            else {
                break;
            }
            
        }
        
        int result = st.size();
        
        return result;
    }
};