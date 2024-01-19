// Time Complexity  : O(N * logN * K)
// Space Complexity : O(N)

//  Problem Link : https://www.geeksforgeeks.org/problems/top-k-numbers3425/1

class Solution {
    public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> result;
        
        vector<int> freq(101 , 0);
        map<int , set<int>> numbers;
        
        for(int i = 0 ; i < N ; i++) {
            
            int prevFreq = freq[arr[i]];
            
            if(prevFreq == 0) {
                numbers[prevFreq+1].insert(arr[i]);
            } else {
                set<int> :: iterator itr;
                
                itr = numbers[prevFreq].find(arr[i]);
                
                numbers[prevFreq].erase(itr);
                
                numbers[prevFreq+1].insert(arr[i]);
            }
            
            freq[arr[i]]++;
            
            map<int , set<int>> :: iterator itr;
            
            itr = numbers.end();
            itr--;
            vector<int> vect;
            
            while(true) {
                set<int> st = itr->second;
                
                for(auto it = st.begin() ; it != st.end() ; it++) {
                    vect.push_back(*it);
                    
                    if(vect.size() == K)
                    break;
                }
                
                if(vect.size() == K)
                break;
                
                
                if(itr == numbers.begin())
                break;
                
                itr--;
            }
            
            result.push_back(vect);
        }
        
        return result;
    }
};