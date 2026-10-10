class Solution {
public:
    int climbStairs(int n) {
        int a=1;
        int b=2;
        int k=a+b;
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else if(n==3){
            return k;
        }
        
      for(int i=4;i<=n;i++){
        a=b;
        b=k;
          k=a+b;
      }
    return k;
    }
};