     class Solution {
public:
   
    bool issafe(int row, int col,vector<vector<int>>board,int n ){
        int x = row;
        int y = col;
        while(y>=0){
            if(board[x][y]==1){
                return false;
            }
            y--;
        }
        y= col;

        while(x>=0&&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x--;
            y--;
        }
        x=row;
        y=col;
        while(x<n&&y>=0){
            if(board[x][y]==1){
                return false;
            }
            x++;
            y--;
        }
        return true;

    }
    void solve(int col,int& ans,vector<vector<int>>board,int n){
        if(col==n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(i,col,board,n)){
                board[i][col]=1;
                solve(col+1,ans,board,n);
                board[i][col]=0;
            }
        }
             
    }
    int totalNQueens(int n) {
        int ans=0;
        vector<vector<int>>board(n,vector<int>(n,0));

        solve(0,ans,board,n);
        return ans;
    }
};
