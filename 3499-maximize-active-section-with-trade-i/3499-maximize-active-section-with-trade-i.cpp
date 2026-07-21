class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
        }
        string t = "1" + s + "1";

        vector<pair<char, int>> margin;

        for (char c : t) {
            if (margin.empty() || margin.back().first != c)
                margin.push_back({c, 1});
            else
                margin.back().second++;
        }

        int gain = 0;

        for (int i = 1; i + 1 < margin.size(); i++) {
            if (margin[i].first == '1') {
                gain = max(gain,
                           margin[i - 1].second + margin[i + 1].second);
            }
        }

        return ones + gain;
    }
};