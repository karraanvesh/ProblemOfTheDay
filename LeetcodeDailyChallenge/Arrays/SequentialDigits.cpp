// Time  Complexity : O(1)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02

class Solution {
    private :
    void generateNumbers(int num , int low , int high , vector<int> &result) {

        while(true) {
            int prevDigit = num%10;

            if(num >= low and num <= high)
            result.push_back(num);

            if(prevDigit == 9)
            break;

            int nextDigit = prevDigit + 1;
            num = num*10 + nextDigit;
        }

        return ;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;

        for(int i = 1 ; i <= 9 ; i++) {
            generateNumbers(i , low , high , result);
        }

        sort(result.begin() , result.end());

        return result;
    }
};