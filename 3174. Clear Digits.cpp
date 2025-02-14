class Solution {
    public:
        string clearDigits(string s) {
            stack<char>st;
    
            for(int i=0;i<s.size();i++){
                if(s[i]>='0'&&s[i]<='9'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
         
            s="";
            while(!st.empty()){
                s.push_back(st.top());
                st.pop();
            }
            reverse(s.begin(),s.end());
            return s;
        }
    };