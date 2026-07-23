class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()==1||nums.size()==2){
            return nums.size();
        }
        int i=2;
        while(nums.size()>=pow(2,i)){
            i++;
        }
        return pow(2,i);
    }
};