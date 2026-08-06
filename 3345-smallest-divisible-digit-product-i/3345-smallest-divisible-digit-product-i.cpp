class Solution {
public:
    bool check(int n,int k){
        int i=1;
        int ans=1;
        while(n){
            int ch = n%10;
            ans*=ch;
            n/=10; 
        }
        if(ans%k==0){
            return true;
        }
        return false;
    }
    int smallestNumber(int n, int t) {
        while(!check(n,t)){
                n++;
        }
        return n;
    }
};