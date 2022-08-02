class Solution {
public:
    void dfs(vector<vector<char>>& board, int row, int col)
    {
        // we check for out of bound things
        if(row<0 || col<0 || row>=board.size() || col>=board[0].size() || board[row][col]!='O') return;
        // we mark the boudary nodes as Z as they are not going to be surrounded on all 4 direction 
        board[row][col]='Z';
        
        // make calls for 4 direction
        dfs(board, row+1, col); // down
        dfs(board, row-1, col); // up
        dfs(board, row, col+1); // right
        dfs(board, row, col-1); // left
    }
    void solve(vector<vector<char>>& board) {
        // we can use DFS/BFS to see the adj ele in board which are having zero
        // we check for the boundary Os as they are not going to change
        for(int i=0; i<board.size(); i++)
        {
            dfs(board, i, 0); // first col diff rows
            dfs(board, i, board[0].size()-1); // last col, diff rows
        }
        for(int i=0; i<board[0].size(); i++)
        {
            dfs(board, 0, i); // first row diff cols
            dfs(board, board.size()-1, i); // last row, diff cols
        }
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='Z') // they are the ones on boundary
                {
                    board[i][j]='O';
                }
                else if(board[i][j]=='O') // the ones who are not Z
                {
                    board[i][j]='X';
                }
            }
        } 
    }
};