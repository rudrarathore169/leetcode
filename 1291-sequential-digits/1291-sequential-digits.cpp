class Solution {
public:
    void solve(vector<int>&ans,int ld,int hd,int low,int high){
          
        while(ld<=hd){
            long long checker=0;
            long long  cnt = 1;
            for(int i=9;i>9-ld;i--){
                checker+=i*cnt;
                cnt*=10;
            }
            cnt/=10;
            for(int i=9-ld;i>=1;i--){
                if(checker>=low&&checker<=high){
                    ans.push_back(checker);
                }
                checker/=10;
                checker+=i*cnt;
            }
            if(checker >= low && checker <= high)
            ans.push_back(checker);
           ld= ld+1;
        }
    }
    vector<int> sequentialDigits(int low, int high){
       int ld = to_string(low).size();
        int hd = min((int)to_string(high).size(), 9);
        vector<int>ans;

        solve(ans,ld,hd,low,high);
        sort(ans.begin(), ans.end());
            return ans;
    }
};