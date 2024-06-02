#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string intToRoman(int num) {
        // I	1
        // V	5
        // X	10
        // L	50
        // C	100
        // D	500
        // M	1000

        string roman;
        while (num >= 1000) {
            num -= 1000;
            roman += "M";
        }
        if (num >= 900) {
            num -= 900;
            roman += "CM";
        }
        if (num >= 500) {
            num -= 500;
            roman += "D";
        }
        if (num >= 400) {
            num -= 400;
            roman += "CD";
        }
        while (num >= 100) {
            num -= 100;
            roman += "C";
        }
        if (num >= 90) {
            num -= 90;
            roman += "XC";
        }
        if (num >= 50) {
            num -= 50;
            roman += "L";
        }
        if (num >= 40) {
            num -= 40;
            roman += "XL";
        }
        while (num >= 10) {
            num -= 10;
            roman += "X";
        }
        if (num >= 9) {
            num -= 9;
            roman += "IX";
        }
        if (num >= 5) {
            num -= 5;
            roman += "V";
        }
        if (num >= 4) {
            num -= 4;
            roman += "IV";
        }
        while (num >= 1) {
            num -= 1;
            roman += "I";
        }
        return roman;
    }
};

class SolutionV2 {
   public:
    map<int, char> table;
    SolutionV2() {
        table[1] = 'I';
        table[5] = 'V';
        table[10] = 'X';
        table[50] = 'L';
        table[100] = 'C';
        table[500] = 'D';
        table[1000] = 'M';
    }
    string intToRoman(int num) {
        string roman;
        while (num >= 1000) {
            num -= 1000;
            roman += "M";
        }
        for (int level = 100; level >= 1; level /= 10) {
            if (num >= level * 9) {
                num -= level * 9;
                roman += table[level];
                roman += table[level * 10];
            }
            if (num >= level * 5) {
                num -= level * 5;
                roman += table[level * 5];
            }
            if (num >= level * 4) {
                num -= level * 4;
                roman += table[level];
                roman += table[level * 5];
            }
            while (num >= level) {
                num -= level;
                roman += table[level];
            }
        }
        return roman;
    }
};