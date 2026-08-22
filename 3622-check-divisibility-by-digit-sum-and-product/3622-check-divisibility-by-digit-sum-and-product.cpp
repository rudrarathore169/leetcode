class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int temp = n;
        int prod=1;
        while(temp){
            sum+=temp%10;
            prod*=temp%10;
            temp/=10;
        }
        if(n%(sum+prod)==0){
            return true;
        }
        return false;
    }
};