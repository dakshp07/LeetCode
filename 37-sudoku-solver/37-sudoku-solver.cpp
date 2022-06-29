class Solution {
public:
    // the below function will help us in keeing a track of the rules
    bool isValid(vector<vector<char>> &board, int row, int col, char c)
    {
        for(int i=0; i<9; i++) // traverse all 9 rows and cols
        {
            if(board[i][col]==c) // if any match in cols
            {
                return false;
            }
            if(board[row][i]==c) // if any match in row
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) // check the sub boxes of grid
            {
                return false;
            }
        }
        return true;
    }
    // the below solve function will try us to find the empty ele in board and peform operations on it
    bool solve(vector<vector<char>> &board)
    {
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j]=='.') // if the ele is empty
                {
                    // lets try all chars ie from 1-9
                    for(char c='1'; c<='9'; c++)
                    {
                        // we will create a helper function that helps us in checking if its vald to put a char c in any given position
                        // ie if we are following rules
                        if(isValid(board, i, j, c))
                        {
                            board[i][j]=c; // we keep char if we follow rules
                            if(solve(board)==true) // after keeping char we make recursive calls for other empty places in board
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.'; // make it empty again if we get the recursive call as false
                            }   
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        // again we do something similar to what we did in n queens
        // we try to fill out all the possibilities in any ele i
        // and make recursive calls on other ele to see if its possible to keep diff values in other indexes
        // if its possible our recursive calls true to its parent in tree and if we reach our top node we get our ans
        solve(board); // our function
    }
};