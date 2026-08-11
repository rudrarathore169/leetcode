class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=nums[0];
        int n= nums.size();
        // int currans=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                ans+=nums[i];
            }
            else{
                break;
            }
        }
        
        unordered_map<int,bool>presence;
        for(int i=0;i<n;i++){
            presence[nums[i]]=true;
        }

        while(presence[ans]){
            ans++;
        }

        return ans;
    }
};