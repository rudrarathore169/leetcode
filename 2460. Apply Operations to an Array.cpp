class Solution {
    public:
        vector<int> applyOperations(vector<int>& arr) {
            vector<int>ans;
            for(int i=0;i<arr.size()-1;i++){
                if(arr[i]==arr[i+1]){
                   arr[i]=arr[i]*2;
                   arr[i+1]=0;
                }
            }
            for(int i=0;i<arr.size();i++){
                if(arr[i]!=0){
                    ans.push_back(arr[i]);
                }
            }
            
            for(int i=arr.size()-ans.size();i>0;i--){
                ans.push_back(0);
            }
            return ans;
        }
    };