class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        
        for(int j=0;j<word.length();j++){
            ans+=j/8 +1;
        }
        return ans;
    }
};