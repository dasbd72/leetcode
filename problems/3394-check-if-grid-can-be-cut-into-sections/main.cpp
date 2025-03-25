#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int countCuts(vector<pair<int, int>>& segments) {
        sort(segments.begin(), segments.end());
        int first = 0, end = 0, cut = 0;
        for (const auto& segment : segments) {
            if (segment.first >= end) {
                if (first == 0) {
                    first = 1;
                } else {
                    cut += 1;
                }
            }
            end = max(end, segment.second);
        }
        return cut;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x_segments, y_segments;
        for (const auto& rectangle : rectangles) {
            x_segments.emplace_back(rectangle[0], rectangle[2]);
            y_segments.emplace_back(rectangle[1], rectangle[3]);
        }
        return countCuts(x_segments) >= 2 || countCuts(y_segments) >= 2;
    }
};