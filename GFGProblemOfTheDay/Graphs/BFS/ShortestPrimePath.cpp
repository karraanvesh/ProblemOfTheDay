// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1

class Solution{   
    private :
    int ct = 0;
    int sieve[10001];
    
    void precompute() {
        
        int n = 10000;
        
        for(int i = 1  ; i <= n ; i++) {
            sieve[i] = 1;
        }
        
        for(int i = 2 ; i*i < n ; i++) {
            
            if(sieve[i]) {
                
                for(int j = i*i ; j < n ; j += i) {
                    sieve[j] = 0;
                }
            }
        }
        
        return ;
    }
    
    void numToVector(int num , vector<int> &currNum) {
        
        while(num > 0) {
            currNum.push_back(num%10);
            num /= 10;
        }
        
        reverse(currNum.begin() , currNum.end());
        
        return ;
    }
    int vectorToNum(vector<int> &currNum) {
        
        int num = 0;
        
        for(int i = 0 ; i < currNum.size() ; i++) {
            num = num*10 + currNum[i];
        }
        
        return num;
    }
public:
    int solve(int Num1,int Num2)
    {   
        if(Num1 == Num2) return 0;
        
        ct++;
        
        if(ct == 1) {
            precompute();
        }
        
        queue<pair<int,int>> q;
        set<int> st;
        
        q.push({Num1 , 0});
        st.insert(Num1);
        
        while(!q.empty()) {
            int num = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            vector<int> currNum;
            
            numToVector(num , currNum);
            
            for(int i = 0 ; i < currNum.size() ; i++) {
                
                int currDigit = currNum[i];
                
                for(int j = 0 ; j <= 9 ; j++) {
                    
                    if(j == 0 and i == 0)
                    continue;
                    
                    if(j == currDigit)
                    continue;
                    
                    currNum[i] = j;
                    int nextNum = vectorToNum(currNum);
                    currNum[i] = currDigit;
                    
                    if(st.count(nextNum) == 0 and sieve[nextNum]) {
                        
                        if(nextNum == Num2) return (1 + steps);
                        
                        st.insert(nextNum);
                        q.push({nextNum , 1 + steps});
                    }
                }
            }
        }
        
        return -1;
    }
};