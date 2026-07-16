class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int>mx;
        int maxi=-1;
        for(int i=0;i<nums.size();i++){
            maxi = max(maxi,nums[i]);
            mx.push_back(maxi);
        }

        vector<int>prefixGcd(nums.size());
        for(int i=0;i<nums.size();i++){
            prefixGcd[i]=(gcd(nums[i],mx[i]));
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        int s=0;
        int e = nums.size()-1;
        long long ans=0;
        while(s<e){
            ans+=gcd(prefixGcd[s++],prefixGcd[e--]);
        }
        return ans;
    }
};