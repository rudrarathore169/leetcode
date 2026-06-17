class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int>right(nums.size());
        left[0]=1;;
        for(int i=1;i<nums.size();i++){
            left[i]=(nums[i-1]*left[i-1]);
        }
        right[nums.size()-1]=1;
        for(int i=nums.size()-2;i>=0;i--){
            right[i]=(nums[i+1]*right[i+1]);
        }
            vector<int>ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(left[i]*right[i]);
        }
        return ans;
    }
};