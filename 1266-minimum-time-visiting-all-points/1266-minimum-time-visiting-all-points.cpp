class Solution {
public:
    void find(vector<int>v,int& x, int& y, int& ans ){
        while(x!=v[0]||y!=v[1]){
            if(v[0]>x){
               x++;
            }
            else if(v[0]<x){
                x--;
            }

            if(v[1]>y){
               y++;
            }
            else if(v[1]<y){
                y--;
            }
            ans++;
            
        }
    }
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans=0;
        int x = points[0][0];
        int y = points[0][1]; 

        for(int i=1;i<points.size();i++){
            find(points[i],x,y,ans);
        }
        return ans;
    }
};