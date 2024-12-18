class Solution {
public:
    bool isBalanced(string num) {
        int evensum=0;
        int oddsum=0;
        
        for(int i=0;i<num.size();i++){
            if(i%2==0){
evensum+=num[i]-'0';
            }
            else{
             oddsum+=num[i]-'0';
            }
}
        return evensum==oddsum;
    }
};