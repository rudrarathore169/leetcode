class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans=0;
         auto check = [&](int curr,int dir)->bool{
            vector<int>arr = nums;
          
            while(curr>=0&& curr<n){
                if(arr[curr]==0){
                    curr += dir;
                }
                else{
                    arr[curr]-=1;
                    dir*=-1;
                    curr+=dir;
                }
            }

            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    return false;
                }
            }
            return true;
         };
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                if(check(i,1)){
                    ans++;
                }
                if(check(i,-1)){
                    ans++;
                }
            }
            
        }
        return ans;
    }
};