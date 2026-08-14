class Solution {
public:
    int maximumLengthSubstring(string s) {
        int i=0;
        int j=0;
        vector<int>have(26,0);
        int realans=0;
        int ans=0;
        while(i<s.length()&&j<s.length()){
            int v = s[j]-'a';
            int u = s[i]-'a';

            if(have[v]<2){
                ans++;
                have[v]++;
                j++;
            }
            else{
                have[u]--;
                ans--;
                i++;
            }
            realans = max(realans,ans);
        }
        return realans;
    }
};