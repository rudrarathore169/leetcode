class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<long long> freq(maxValue + 1, 0);

        for (int x : nums)
            freq[x]++;
        vector<long long> gcdCount(maxValue + 1, 0);
        for (int g = maxValue; g >= 1; g--) {
            long long cnt = 0;

            for (int multiple = g; multiple <= maxValue; multiple += g)
                cnt += freq[multiple];
            gcdCount[g] = cnt * (cnt - 1) / 2;

            for (int multiple = 2 * g; multiple <= maxValue; multiple += g)
                gcdCount[g] -= gcdCount[multiple];
        }


        vector<long long> prefix(maxValue + 1, 0);

        for (int i = 1; i <= maxValue; i++)
            prefix[i] = prefix[i - 1] + gcdCount[i];

        
        vector<int> answer;

        for (long long q : queries) {

            int gcdValue = lower_bound(
                               prefix.begin() + 1,
                               prefix.end(),
                               q + 1)
                           - prefix.begin();

            answer.push_back(gcdValue);
        }

        return answer;
    }
};