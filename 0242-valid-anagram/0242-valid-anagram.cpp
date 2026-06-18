class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>have;

        for(int i=0;i<s.length();i++){
            have[s[i]]++;
        }

        for(int i=0;i<t.length();i++){
            have[t[i]]--;

        }

        for(auto i:have){
            if(i.second!=0){
                return false;
            }
        }
        return true;}
    
};