class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {  
        unordered_map<int,bool>present;
        vector<int>ans;  
        for(int i=0;i<nums.size();i++){
            if(!present[nums[i]]){
                present[nums[i]]=true;
            }
            else{
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};