class Solution {
public:
    int minimumLength(string s) {
        int ans=0;
        unordered_map<char,int>freq;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(auto i:freq){
            if(i.second%2==0){
                ans+=2;
            }
            else{
                ans++;
            }
        }
        return ans;
    }
};