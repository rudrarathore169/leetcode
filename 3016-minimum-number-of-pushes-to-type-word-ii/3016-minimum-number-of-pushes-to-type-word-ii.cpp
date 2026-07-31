class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<int>pq;
        vector<int>freq(26,0);

        for(int i=0;i<word.length();i++){
            freq[word[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0)
            pq.push(freq[i]);
        }

        int cnt=0;
        int ans=0;
        while(!pq.empty()){
            int a =pq.top();
            pq.pop();
            ans+=a*((cnt/8)+1);
            cnt++;
        }
        return ans;
    }
};