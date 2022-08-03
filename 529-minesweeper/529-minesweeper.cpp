class Solution {
public:
    bool valid(int r, int c, vector<vector<char>> board)
    {
        int m=board.size(),n=board[0].size();
        return(r<m && c<n && r>=0 && c>=0);
    }
    void dfs(int r, int c, vector<vector<char>>& board)
    {
        if(!valid(r,c,board) || board[r][c]=='B')
            return;
        int dir[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int adjMines=0;
        for(int i=0;i<8;i++)
        {
            int nr=r+dir[i][0];
            int nc=c+dir[i][1];
            if(valid(nr,nc,board) && board[nr][nc]=='M')
            {
                adjMines++;
            }
        }
        
        if(adjMines > 0)
        {
            board[r][c]='0'+adjMines;
        }
        else
        {
            board[r][c]='B';
            for(int i=0;i<8;i++)
            {
                int nr=r+dir[i][0];
                int nc=c+dir[i][1];
                dfs(nr,nc,board);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int r=click[0];
        int c=click[1];
        if(board[r][c]=='M')
        {
            board[r][c]='X';
            return board;
        }
        dfs(r,c,board);
        return board;
    }
};