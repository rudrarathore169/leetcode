class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 1;
        for(int i=1;i<n;i++){
            odd+=i*2+1;
        }
        int even=0;
        for(int i=1;i<=n;i++){
            even+=i*2;
        }
        int ans = 1;
        for(int i=1;i<even&&i<odd;i++){
            if(even%i==0&&odd%i==0){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};