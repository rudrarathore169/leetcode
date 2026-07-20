class Solution {
public:
    
void reverse(vector<int> &nums,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int ro = grid.size();
        int col = grid[0].size();
        vector<int> v;
        for(auto &gri:grid){
            for(auto &val:gri){
                v.push_back(val);
            }
        }
        k = k % v.size();
        reverse(v,0,v.size()-k-1);
        reverse(v,v.size()-k,v.size()-1);
        reverse(v,0,v.size()-1);
        int vec = 0;
        for(int i=0;i<ro;i++){
            for(int j=0;j<col;j++){
                grid[i][j] = v[vec];
                vec++;
            }
        }
        return grid;
    }
};