class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // so now rules of sudoku is
        // 1. any number from 1-9 should come once in entire row
        // 2. any number from 1-9 should come once in entire col
        // 3. any number from 1-9 shouldnt be repeated in 3x3 sub grid
        // one way is to keep 3 vectors seen, one for row one for col and one for 3x3 grid
        // and for any ele check if they are repeating in any of these 3
        // but we can use one set and some string modification to check if any char repates
        unordered_set<string> st;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                // now if any ele says "3 found in row 2" and this statement is there in our set
                // we return false
                // in other cases like "found in col 3" or "found in 3x3 box 2-3"
                // we return false
                if(board[i][j]!='.')
                {
                    if(st.count(to_string(board[i][j])+"found in row"+to_string(i)))
                    {
                        return false;
                    }
                
                    if(st.count(to_string(board[i][j])+"found in col"+to_string(j)))
                    {
                         return false;
                    }
                
                    if(st.count(to_string(board[i][j])+"found in 3x3 box"+to_string(i/3)+"-"+to_string(j/3)))
                    {
                        return false;
                    }
                    // if we dont find them
                    // we enter the current ele 3 items
                    // one for row, one for col, one for 3x3 grid
                    st.insert(to_string(board[i][j])+"found in row"+to_string(i));
                    st.insert(to_string(board[i][j])+"found in col"+to_string(j));
                    st.insert(to_string(board[i][j])+"found in 3x3 box"+to_string(i/3)+"-"+to_string(j/3));
                }
            }
        }
        // if we complete our loop we return true
        return true;
    }
};