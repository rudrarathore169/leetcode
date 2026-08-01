class Solution {
public:
    bool solve(vector<int>&nums,int i,int j,int pl1,int pl2,bool check){
        if(i > j){
        return pl1 >= pl2;
        }
        bool l = false;
        bool r = false;
        if(!check){
        l=solve(nums,i+1,j,pl1+nums[i],pl2,!check);
        r=solve(nums,i,j-1,pl1+nums[j],pl2,!check);
        }
        else{
        l=solve(nums,i+1,j,pl1,pl2+nums[i],!check);
        r=solve(nums,i,j-1,pl1,pl2+nums[j],!check);
        }
        if(check)
        return l && r;

        return l||r;
    }
    bool predictTheWinner(vector<int>& nums) {
        int pl1 =0;
        int pl2 =0;

        return solve(nums,0,nums.size()-1,pl1,pl2,false);
    }
};