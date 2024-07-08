#include<string>
#include<vector>
#include <unordered_map>
class Solution {
public:
    int longestPalindrome(string s) {

        int n = s.size();
        int count = 0;
        unordered_map<char, int> mapp;
        int flag = false;

        for (int i = 0; i < n; i++) {
            mapp[s[i]]++;
        }

        for (int i = 0; i < mapp.size(); i++) {
            if (mapp[i] % 2 == 0)
                count += mapp[i];
            else {
                count += mapp[i] - 1;
                flag = true;
            }
        }
        if (flag)
            return count + 1;
        else
            return count;
    }
};