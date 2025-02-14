#include <unordered_map>
#include <vector>

class Solution {
public:
    long long countBadPairs(std::vector<int>& nums) {
        long long n = nums.size();
        long long totalPairs = (n * (n - 1)) / 2;
        
        std::unordered_map<int, long long> freq;
        long long goodPairs = 0;
        
        for (int i = 0; i < n; i++) {
            int val = nums[i] - i;
            if (freq.count(val)) {
                goodPairs += freq[val];  // Every previous occurrence forms a good pair
            }
            freq[val]++;
        }
        
        return totalPairs - goodPairs;
    }
};
