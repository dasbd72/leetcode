#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int length = s.length();
        int word_length = words[0].length();
        unordered_map<string, int> freqs;
        vector<int> answer;
        unordered_map<string, int> memory;
        auto check_mem = [&]() {
            bool match = true;
            for (auto& [word, freq] : freqs) {
                if (memory[word] > freq) {
                    return 1;
                } else if (memory[word] < freq) {
                    match = false;
                }
            }
            return match ? 0 : -1;
        };

        for (auto& word : words) {
            freqs[word] += 1;
        }

        for (int offset = 0; offset < word_length; offset++) {
            int l = offset;
            for (int r = offset; r + word_length - 1 < length; r += word_length) {
                if (freqs.find(s.substr(r, word_length)) == freqs.end()) {
                    memory.clear();
                    l = r + word_length;
                    continue;
                }
                memory[s.substr(r, word_length)]++;
                while (check_mem() > 0) {
                    memory[s.substr(l, word_length)]--;
                    l += word_length;
                }
                if (check_mem() == 0) {
                    answer.push_back(l);
                }
            }
            memory.clear();
        }
        return answer;
    }
};