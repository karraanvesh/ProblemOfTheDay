// Time  Complexity : O(n * logn + 2*n) ~ O(n * logn + n)
// Space Complexity : O(4 * n) ~ O(n)

// Problem Link : https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13

class Solution {
    private :
    static bool comp(vector<int> &v1 , vector<int> &v2) {

        return v1[0] < v2[0];
    }
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        
        int n = positions.size();
        vector<vector<int>> vect;

        for(int i = 0 ; i < n ; i++) {

            int roboPos = positions[i];
            int strength = healths[i];
            int dir = (directions[i] == 'R') ? 1 : 0;
            int pos = i;

            vector<int> v;

            v.push_back(roboPos);
            v.push_back(strength);
            v.push_back(dir);
            v.push_back(pos);

            vect.push_back(v);
        }

        sort(vect.begin() , vect.end() , comp);

        stack<pair<int , int>> st;

        for(int i = 0 ; i < n ; i++) {

            if(vect[i][2]) {
                st.push({vect[i][1] , vect[i][3]});
            }

            else {

                if(st.empty()) {
                    healths[vect[i][3]] = vect[i][1];
                    continue ;
                }

                pair<int , int> prev = st.top();
                int prevStrength = prev.first;

                if(prevStrength == vect[i][1]) {
                    st.pop();
                    healths[prev.second] = healths[vect[i][3]] = -1;
                }

                else if(prevStrength > vect[i][1]) {
                    prev.first--;
                    st.pop();

                    healths[vect[i][3]] = -1;
                    st.push(prev);
                }

                else {

                    while(!st.empty() and vect[i][1] > prev.first) {

                        healths[prev.second] = -1;
                        st.pop();
                        vect[i][1]--;

                        if(st.empty())
                        break;

                        prev = st.top();
                    }

                    i--; 
                }
            }
        }

        while(!st.empty()) {
            pair<int,int> curr = st.top();

            st.pop();

            healths[curr.second] = curr.first;
        }

        vector<int> reduced;

        for(int i = 0 ; i < n ; i++) {
            
            if(healths[i] == -1) continue;

            reduced.push_back(healths[i]);
        }

        healths = reduced;

        return healths;
    }
};