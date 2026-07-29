#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static const long long LIMIT = 1000001;

    // Compute nCr, capped at LIMIT
    long long nCr(int n, int r) {
        if (r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans >= LIMIT)
                return LIMIT;
        }

        return ans;
    }
    long long comb(int len, vector<int>& freq) {
        long long ans = 1;
        int rem = len;

        for (int f : freq) {
            if (f == 0) continue;

            ans *= nCr(rem, f);

            if (ans >= LIMIT)
                return LIMIT;

            rem -= f;
        }

        return ans;
    }

    string solve(int len, int &k, vector<int>& freq) {

        if (len == 0)
            return "";

        for (int c = 0; c < 26; c++) {

            if (freq[c] == 0)
                continue;

            freq[c]--;

            long long cnt = comb(len - 1, freq);

            if (cnt >= k) {
                return char('a' + c) + solve(len - 1, k, freq);
            }

            k -= cnt;
            freq[c]++;
        }

        return "";
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        char mid = '\0';

        int halfLen = 0;

        for (int i = 0; i < 26; i++) {

            if (freq[i] % 2)
                mid = char('a' + i);

            freq[i] /= 2;
            halfLen += freq[i];
        }

        long long total = comb(halfLen, freq);

        if (total < k)
            return "";

        string half = solve(halfLen, k, freq);

        string rev = half;
        reverse(rev.begin(), rev.end());

        if (mid == '\0')
            return half + rev;

        return half + string(1, mid) + rev;
    }
};