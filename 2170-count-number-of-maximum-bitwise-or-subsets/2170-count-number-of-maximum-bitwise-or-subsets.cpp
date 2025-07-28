class Solution {
public:
    int maxOR = 0, count = 0;

    void subset(int index, int currentOR, vector<int>& nums) {
        if (index == nums.size()) {
            if (currentOR == maxOR) {
                count++;
            }
            return;
        }

        
        subset(index + 1, currentOR | nums[index], nums);

        
        subset(index + 1, currentOR, nums);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        
        for (int num : nums) {
            maxOR |= num;
        }

        
        subset(0, 0, nums);

        return count;
    }
};
