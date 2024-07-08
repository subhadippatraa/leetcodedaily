#include <bits/stdc++.h>
#include<string>

class Solution {
public:
    int appendCharacters(string s, string t) {

        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;
        int count = 0;

        while (i < n && j < m) {
            if (s[i] != t[j]) {
                i++;
            } else {
                i++;
                j++;
            }
        }
        return m - j;
    }
};