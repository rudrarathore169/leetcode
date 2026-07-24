class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>pxor;

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                pxor.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>ans;
        for(int i=0;i<nums.size();i++){
            for(auto a : pxor){
                ans.insert(nums[i]^a);
            }
        }
        return ans.size();
    }
};