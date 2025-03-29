#include <bits/stdc++.h>
using namespace std;

// class PrimeUtil {
// public:
//     int size;
//     vector<bool> is_prime;
//     vector<int> primes;
//     void sieve(int n) {
//         if (primes.size() && n < size) {
//             return;
//         }
//         size = n;
//         int sqrt_size = sqrt(size);
//         is_prime.assign(size + 1, true);
//         is_prime[1] = is_prime[0] = false;
//         for (int i = 2; i <= sqrt_size; i++) {
//             if (is_prime[i]) {
//                 primes.emplace_back(i);
//                 for (int j = i * i; j <= size; j += i) {
//                     is_prime[j] = false;
//                 }
//             }
//         }
//     }
//     int primeScore(int n) {
//         if (is_prime[n]) {
//             return 1;
//         }
//         int prime_score = 0;
//         for (const auto& prime : primes) {
//             if (prime > n) {
//                 break;
//             }
//             if (n % prime != 0) {
//                 continue;
//             }
//             prime_score++;
//             while (n % prime == 0) {
//                 n /= prime;
//             }
//         }
//         prime_score += (n > 1);
//         return prime_score;
//     }
// };

class PrimeUtil {
   public:
    int size;
    vector<int> prime_scores;
    void sieve(int n) {
        if (prime_scores.size() && n < size) {
            return;
        }
        size = n;
        prime_scores.assign(size + 1, 0);
        for (int i = 2; i <= size; i++) {
            if (prime_scores[i] == 0) {
                for (int j = i; j <= size; j += i) {
                    prime_scores[j]++;
                }
            }
        }
    }
    int primeScore(int n) {
        return prime_scores[n];
    }
};

PrimeUtil prime_util;

class Solution {
   public:
    static constexpr int modulo = 1e9 + 7;

    long long modPow(long long x, long long n) {
        if (x == 0 || n == 0) {
            return 1;
        }
        long long y = modPow(x, n / 2);
        y *= y;
        y %= modulo;
        if (n & 1) {
            y *= x;
            y %= modulo;
        }
        return y;
    }

    int maximumScore(vector<int>& nums, int k) {
        prime_util.sieve(*max_element(nums.begin(), nums.end()));

        // How many times a number can be used?
        // = (start pos choices) x (end pos choices)
        // Choices should be ones that still make the number dominates
        // all start pos should < current on {primeScore(num)}
        // all end pos should <= current on {primeScore(num)}
        map<long long, long long> num_cnt;
        vector<int> start_pos(nums.size());
        vector<int> end_pos(nums.size());
        {
            stack<tuple<int, int>> stk;
            stk.emplace(0x7fffffff, -1);
            for (int i = 0; i < nums.size(); i++) {
                int prime_score = prime_util.primeScore(nums[i]);
                while (prime_score > get<0>(stk.top())) {
                    stk.pop();
                }
                start_pos[i] = get<1>(stk.top());
                stk.emplace(prime_score, i);
            }
        }
        {
            stack<tuple<int, int>> stk;
            stk.emplace(0x7fffffff, nums.size());
            for (int i = nums.size() - 1; i >= 0; i--) {
                int prime_score = prime_util.primeScore(nums[i]);
                while (prime_score >= get<0>(stk.top())) {
                    stk.pop();
                }
                end_pos[i] = get<1>(stk.top());
                stk.emplace(prime_score, i);
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            num_cnt[nums[i]] +=
                (long long)(end_pos[i] - i) * (i - start_pos[i]);
        }

        long long ans = 1;
        for (auto it = num_cnt.rbegin(); it != num_cnt.rend() && k > 0; it++) {
            long long num = get<0>(*it);
            long long cnt = min((long long)k, get<1>(*it));
            ans *= modPow(num, cnt);
            ans %= modulo;
            k -= cnt;
        }
        return ans;
    }
};