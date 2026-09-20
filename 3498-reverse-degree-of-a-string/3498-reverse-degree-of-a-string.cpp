class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            int tempans=0;
            int k = s[i]-'a';

            tempans = (i+1)*(26-k);
            ans+=tempans;
        }
        return ans;

    }
};