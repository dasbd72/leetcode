#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isVowel(char c) {
        switch (c) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                return true;
            default:
                return false;
        }
    }
    string reverseVowels(string s) {
        int l = 0;
        int r = s.length() - 1;
        while (l < r) {
            while (l < s.length() && !isVowel(s[l])) {
                l++;
            }
            while (r >= 0 && !isVowel(s[r])) {
                r--;
            }
            if (l >= r)
                break;
            swap(s[l], s[r]);
            l++, r--;
        }
        return s;
    }
};