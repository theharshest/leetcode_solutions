class Solution {
public:
    bool iscomplete(vector<vector<char> > &board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    return false;
            }
        }
        
        return true;
    }

    pair<int, int> nextrowcol(vector<vector<char> > &board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                {
                    pair<int, int> rowcol;
                    rowcol.first = i;
                    rowcol.second = j;
                    return rowcol;
                }
            }
        }
    }

    bool isvalid(vector<vector<char> > &board, char val, int row, int col)
    {
        for(int i=0; i<9; i++)
        {
            if(board[row][i]==val)
                return false;
        }
        
        for(int i=0; i<9; i++)
        {
            if(board[i][col]==val)
                return false;
        }
        
        int startrow=row/3, startcol=col/3;
        startrow*=3;
        startcol*=3;
        
        for(int i=startrow; i<startrow+3; i++)
        {
            for(int j=startcol; j<startcol+3; j++)
            {
                if(board[i][j]==val)
                    return false;
            }
        }
        
        return true;
    }

    bool solveSudokuutil(vector<vector<char> > &board, pair<int, int> rowcol)
    {
        if(iscomplete(board))
            return true;
        
        int row=rowcol.first;
        int col=rowcol.second;
        
        for(int i=1; i<=9; i++)
        {
            char c='0'+i;
            if(isvalid(board, c, row, col))
            {
                board[row][col]=c;
                if(solveSudokuutil(board, nextrowcol(board)))
                    return true;
                board[row][col]='.';
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char> > &board) {
        pair<int, int> rowcol = nextrowcol(board);
        solveSudokuutil(board, rowcol);
    }
};
