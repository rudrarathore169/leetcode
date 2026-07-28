class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26,0);
        char mide='\0';
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        string st="";
        for(int i=0;i<26;i++){
            if(freq[i]%2==0){
                st += string(freq[i] / 2, 'a' + i);
            }
            else{
                mide = 'a'+i;
                st += string(freq[i] / 2, 'a' + i);
            }
        }
        string ans = st;
        reverse(st.begin(), st.end());
        if (mide != '\0') ans += mide;
        ans += st;
        return ans;
    }
};