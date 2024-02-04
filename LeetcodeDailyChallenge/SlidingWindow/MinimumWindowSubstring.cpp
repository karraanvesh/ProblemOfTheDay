// Time  Complexity : O(n + m)
// Space Complexity : O(1)

// Problem Link : https://leetcode.com/problems/minimum-window-substring/description/?envType=daily-question&envId=2024-02-04

class Solution {
public:
    string minWindow(string s, string t) {
       int n = s.length();
       int m = t.length();

       int left , right , uniqueCount , ct;
       left = right = uniqueCount = ct = 0;

       vector<int> mp1(256 , 0) , mp2(256 , 0);

       for(int i = 0 ; i < m ; i++) {
           int currChar = t[i];
           mp1[currChar]++;

           if(mp1[currChar] == 1)
           uniqueCount++;
       }

       int start , end , minLen;
       minLen = INT_MAX;
       start = end = -1;

       while(right < n) {
           int currChar = s[right];
           mp2[currChar]++;

           if(mp2[currChar] == mp1[currChar])
           ct++;

           if(ct == uniqueCount) {

               int prevChar = s[left];

               while(left <= right and mp2[prevChar] > mp1[prevChar]) {
                   mp2[prevChar]--;
                   left++;
                   prevChar = s[left];
               }

               int len = (right - left) + 1;

               if(len < minLen) {
                   minLen = len;
                   start = left;
                   end = right;
               }

               mp2[prevChar]--;
               left++;
               ct--;

               
           }

           right++;
       }

       string result;

       if(start == -1) return result;

       for(int i = start ; i <= end ; i++) {
           result += s[i];
       }

       return result;
    }
};