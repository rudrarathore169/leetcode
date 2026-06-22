class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>freq;
        for(char i:text){
            freq[i]++;
        }
        string s = "balon";
        int ans = INT_MAX;
        for(char i:s){
            if(i=='l'||i=='o'){
                 ans = min(ans,freq[i]/2);
            }
            else
            ans = min(ans,freq[i]);
        }
        return ans;
    }
};