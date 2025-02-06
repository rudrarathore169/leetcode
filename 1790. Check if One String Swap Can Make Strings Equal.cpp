class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        bool ans  =0;
        int count=0;
        int i= -1;
        int j=-1;
        for(int k = 0;k<s1.size();k++){
            if(s1[k]!=s2[k]){
                i = j;
                j = k;
                count++;
                if(count>2){
                    return false;
                }
            }
        }
        if(count==0){
            return true;
        }
       else if(count==2&&s1[i]==s2[j]&&s1[j]==s2[i]){
            ans = true;
        }
        else{
            return false;
        }
        return ans;
    }
};