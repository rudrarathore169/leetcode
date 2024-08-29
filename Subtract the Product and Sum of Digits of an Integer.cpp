class Solution {
public:
    int subtractProductAndSum(int n) {
        int check = n;
        int sum =0;
        int prod =1;
        while(check>=10){
           sum =  sum + (check%10);
           check = check/10;
        }
        sum = sum + check;
        while(n>=10){
            prod = prod*(n%10);
            n = n/10;
        }
        prod = prod*n;

        return prod - sum;
    }
};