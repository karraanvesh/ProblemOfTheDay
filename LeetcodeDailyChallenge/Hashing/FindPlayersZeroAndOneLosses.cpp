// Time Complexity : O(n)
// Space Complexity : O(m)
// where m are the number of teams given in the input 

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();

        map<int , pair<int,int>> mp;

        for(int i = 0 ; i < n ; i++) {
            int wonTeam = matches[i][0];
            int lostTeam = matches[i][1];

            mp[wonTeam].first++;
            mp[lostTeam].second++;
        }

        map<int , pair<int , int>> :: iterator itr;
        vector<int> allWins , oneLoss;

        for(itr = mp.begin() ; itr != mp.end() ; itr++) {

            pair<int , int> p = itr->second;
            int team = itr->first;

            if(p.second == 0) 
            allWins.push_back(team);

            if(p.second == 1)
            oneLoss.push_back(team);
        }

        vector<vector<int>> answer;
        
        answer.push_back(allWins);
        answer.push_back(oneLoss);

        return answer;
    }
};