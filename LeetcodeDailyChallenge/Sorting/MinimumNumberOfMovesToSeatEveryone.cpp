// Time  Complexity : O(n * logn)
// Space Complexity: O(1)

// Problem Link : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/description/?envType=daily-question&envId=2024-06-13

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        int n = seats.size();
        
        sort(seats.begin() ,seats.end());
        sort(students.begin() , students.end());
        
        int result = 0;
        
        for(int i = 0 ; i < n ; i++)    {
            int diff = abs(seats[i] - students[i]);
            
            result += diff;
        }
        
        return result;
    }
};