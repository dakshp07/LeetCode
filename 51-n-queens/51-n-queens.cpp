class Solution {
public:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        // we will check for left sides, since the rights are yet to filled
        // (recursion is always moved from left to right)
        // so we will check upper diagonal, horizontal, lower diagonal to see if queens are safe or not
        // first upper diagonal
        int og_row=row;
        int og_col=col;
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q') return false; // if we find a queen we return false
            row--; // or else we move on
            col--;
        }
        // second horizontal
        // no row changes, only col
        col=og_col;
        row=og_row;
        while(col>=0)
        {
            if(board[row][col]=='Q') return false;
            col--;
        }
        // third is lower diagonal
        col=og_col;
        row=og_row;
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true; // if we return no where means we are doing all good, return true if we still in function
        
    }
    void func(int col, vector<string> &board, vector<vector<string>> &ans, string s, int n)
    {
        if(col==n) // if we reach last col, we just add the board in vector ans as its an answer
        {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) // we traverse every row to see if we put any string in the given row and col
        {
            if(isSafe(row, col, board, n)) // helper function to see if rules are followed
            {
                board[row][col]='Q'; // keeping the queen
                func(col+1, board, ans, s, n); // seeing for next col
                // backtracking our queen as we now move to check next row
                board[row][col]='.'; // removing the queen as we revert back in our recurison tree
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        // rules: every row has 1 queen, every col has 1 queen, and no queen can attack other queen (they attack if the queens lie in horizontal, diagonal, vertical direction)
        // the logic is to try and see if we can fill colums
        // if we fill col we check other queen position and draw the tree
        // we check and revert back the recursion if unable to place any queen
        vector<vector<string>> ans; // ans vector
        vector<string> board(n); //  our board of size n*n
        string s(n, '.'); // n size empty strings
        for(int i=0; i<n; i++)
        {
            board[i]=s; // we push n size empty strings to our board
        }
        func(0, board, ans, s, n); // function to solve the board
        return ans;
    }
};