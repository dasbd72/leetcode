#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int strStr(string haystack, string needle) {
        for (int i = 0; i < haystack.length(); i++) {
            bool match = true;
            for (int j = 0; j < needle.length(); j++) {
                if (i + j >= haystack.length() || haystack[i + j] != needle[j]) {
                    match = false;
                }
            }
            if (match) {
                return i;
            }
        }
        return -1;
    }
};