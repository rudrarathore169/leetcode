#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dosum(int a) {
        int ans = 0;
        while (a) {
            ans += a % 10;
            a /= 10;
        }
        return ans;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap;
        int ans = -1;

        for (int num : nums) {
            int digitSum = dosum(num);
            if (digitSumMap.count(digitSum)) {
                ans = max(ans, num + digitSumMap[digitSum]); 
                digitSumMap[digitSum] = max(digitSumMap[digitSum], num);
            } else {
                digitSumMap[digitSum] = num;
            }
        }

        return ans;
    }
};
