// Time  Complexity : O(m*logm + 2*n)
// Space Complexity : O(m)

// Problem Link : https://leetcode.com/problems/number-of-atoms/description/?envType=daily-question&envId=2024-07-14

class Solution {
    private :
    bool isLowerCase(char ch) {
        return (ch >= 'a' and ch <= 'z');
    }

    bool isDigit(char ch) {
        return (ch >= '0' and ch <= '9');
    }
    string formula(string &str , int &ind , int n) {

        string s;

        while(ind < n and isLowerCase(str[ind])) {
            s += str[ind];
            ind++;
        }

        return s;
    }

    int noOfAtoms(string &str , int &ind , int n) {

        int num = 0;

        while(ind < n and isDigit(str[ind])) {
            num = num*10 + (str[ind] - '0');
            ind++;
        }

        return num;
    }

    map<string , int> merge(map<string , int> &mp1 , map<string , int> &mp2) {

        map<string , int> :: iterator itr;

        for(itr = mp2.begin() ; itr != mp2.end() ; itr++) {
            string s = itr->first;

            if(mp1.find(s) != mp1.end()) {
                mp1[s] += itr->second;
            }

            else {
                mp1.insert({s , itr->second});
            }
        }

        return mp1;
    }
    map<string , int> f(string &str , int &ind , int n) {

        map<string , int> mp;

        if(ind == n) return mp;

        while(ind < n and str[ind] != '(' and str[ind] != ')') {

            string s;
            s += str[ind];
            ind++;
            
            s += formula(str , ind , n);
            int freq = noOfAtoms(str , ind , n);

            if(freq == 0)
            freq = 1;

            mp[s] += freq;
        }

        map<string , int> mp1;

        if(str[ind] == '(') {
            ind++;
            mp1 = f(str , ind , n);

            if(ind < n and isDigit(str[ind])) {

                int freq = noOfAtoms(str , ind , n);

                if(freq == 0)
                freq = 1;

                map<string , int> :: iterator itr;

                for(itr = mp1.begin() ; itr != mp1.end() ; itr++) {
                    itr->second = itr->second * freq;
                }
            }

            merge(mp , mp1);
        }

        if(str[ind] == ')') {
            ind++;

            return mp;
        }

        mp1 = f(str , ind , n);

        merge(mp , mp1);
        return mp;
    }
public:
    string countOfAtoms(string formula) {

        int ind = 0;
        int n = formula.length();

        map<string , int> mp = f(formula , ind , n);

        vector<pair<string , int>> vect;

        map<string , int> :: iterator itr;

        for(itr = mp.begin() ; itr != mp.end() ; itr++) {

            vect.push_back({itr->first , itr->second});
        }

        sort(vect.begin() , vect.end());

        string result;
        int m = vect.size();

        for(int i = 0 ; i < m ; i++) {

            string s = vect[i].first;
            int num = vect[i].second;

            if(num == 1) {
                result += s;
                continue;
            }

            vector<int> v;

            while(num > 0) {
                v.push_back(num%10);
                num /= 10;
            }

            reverse(v.begin() , v.end());

            for(int i = 0 ; i < v.size() ; i++) {
                s += ('0' + v[i]);
            }

            result += s;
        }

        return result;
    }
};