class Solution {
public:
     int findmin(vector<int>ans){
            int res = -1;
            int check=INT_MAX;
            for(int i=0;i<ans.size();i++){
               if(check>ans[i]){
                check = ans[i];
                res = i;
               }
            }
            return res;
        }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
       
       vector<int>ans = nums;
       while(k--){
        int mini = findmin(ans);
        ans[mini] *=multiplier; 
       } 
       return ans;
    }
};