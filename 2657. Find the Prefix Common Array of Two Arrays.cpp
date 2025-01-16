class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int checker=0;
        vector<int>ans;
        unordered_map<int,bool>contains;
        for(int i=0;i<A.size();i++){
            if(contains[A[i]]){
                checker++;
            }
            
                contains[A[i]]=true;
            
            if(contains[B[i]]){
                checker++;
            }
            
                contains[B[i]]=true;
            
            ans.push_back(checker);
        }
        return ans;
    }
};