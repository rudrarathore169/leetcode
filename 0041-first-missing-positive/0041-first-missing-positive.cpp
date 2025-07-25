class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int neg = 0;
        int pos_max=1;
        unordered_map<int,bool>available;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                neg++;
            }
            if(nums[i]>0){
                available[nums[i]]=true;
            }
            pos_max = max(pos_max,nums[i]);
        }

        

        for(int i=1;i<=pos_max;i++){
            if(!available[i]){
                return i;
            }
        }
        return ++pos_max;
    }
};