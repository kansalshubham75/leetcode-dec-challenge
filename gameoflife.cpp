class Solution {
public:
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int calcLiveNeighbours(int i,int j,vector<vector<int>>& board){
        int n=board.size(),m=board[0].size(),ans=0;
        for(auto& d:dir){
            int nr=i+d[0],nc=j+d[1];
            if(nr<n && nc<m && nr>=0 && nc>=0 && (board[nr][nc]==1 || board[nr][nc]==2))ans++;
        }
        return ans;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size(),m=board[0].size();
        //set transition
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live=calcLiveNeighbours(i,j,board);
                if(board[i][j]){
                    if(live>=2 && live<=3)board[i][j]=1;
                    else    board[i][j]=2;
                }else{
                    if(live==3)board[i][j]=3;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2)board[i][j]=0;
                if(board[i][j]==3)board[i][j]=1;
            }
        }
    }
};