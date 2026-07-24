class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();
        int mx = 0;
        for (auto x : nums)
            mx = max(mx, x);


        int u = 1;
        while (u <= mx)
            u <<= 1;

        vector<int> s(u);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                s[nums[i] ^ nums[j]] = 1;
            }
        }

        vector<int> t(u);

        for (int i = 0; i < u; i++) {
            if (s[i] == 0)
                continue;

            for (auto x : nums)
                t[x ^ i] = 1;
        }

        int ans = 0;
        for (int i = 0; i < u; i++) {
            if (t[i])
                ans++;
        }

        return ans;
    }
};