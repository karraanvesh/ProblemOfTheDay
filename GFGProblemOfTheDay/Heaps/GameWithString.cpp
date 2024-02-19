// Time  Complexity : O(k * logp)
// Space Complexity : O(n)
// where n is the length of string and p is number of distinct alphabets 
// and k number of alphabets to be removed

// Problem Link : https://www.geeksforgeeks.org/problems/game-with-string4100/1

class Solution{
public:
    int minValue(string s, int k){
        int n = s.length();
        
        vector<int> mp(26 , 0);
        
        for(int i = 0 ; i < n ; i++) {
            int currChar = s[i] - 'a';
            mp[currChar]++;
        }
        
        priority_queue<int> pq;
        
        for(int i = 0 ; i < 26 ; i++) {
            if(mp[i]) {
                pq.push(mp[i]);
            }
        }
        
        while(k > 0 and !pq.empty()) {
            int maxFreq = pq.top();
            
            pq.pop();
            
            maxFreq--;
            
            if(maxFreq) {
                pq.push(maxFreq);
            }
            
            k--;
        }
        
        int result = 0;
        
        while(!pq.empty()) {
            int currEle = pq.top();
            pq.pop();
            
            result += (currEle * currEle);
        }
        
        return result;
    }
};