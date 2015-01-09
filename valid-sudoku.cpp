class Solution {
public:
    bool checkrows(vector<vector<char> > &board)
    {
        for(int i=0; i<9; i++)
        {
            unordered_set<char> nums;
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                    continue;

                if(nums.find(board[i][j]) != nums.end())
                    return false;
                else
                    nums.insert(board[i][j]);
            }
        }
        
        return true;
    }

    bool checkcols(vector<vector<char> > &board)
    {
        for(int i=0; i<9; i++)
        {
            unordered_set<char> nums;
            for(int j=0; j<9; j++)
            {
                if(board[j][i]=='.')
                    continue;

                if(nums.find(board[j][i]) != nums.end())
                    return false;
                else
                    nums.insert(board[j][i]);
            }
        }
        
        return true;
    }

    bool checksquare(vector<vector<char> > &board, int i1, int i2)
    {
        unordered_set<char> nums;
        int rowmax=i1+2, colmax=i2+2;
        for(int i=i1; i<=rowmax; i++)
        {
            for(int j=i2; j<=colmax; j++)
            {
                if(board[i][j]=='.')
                    continue;

                if(nums.find(board[i][j]) != nums.end())
                    return false;
                else
                    nums.insert(board[i][j]);
            }
        }
        
        return true;
    }

    bool checksquares(vector<vector<char> > &board)
    {
        int i1, i2;
        i1=0; i2=0;
        bool sq1=checksquare(board, i1, i2);
        
        i1=0; i2=3;
        bool sq2=checksquare(board, i1, i2);

        i1=0; i2=6;
        bool sq3=checksquare(board, i1, i2);
        
        i1=3; i2=0;
        bool sq4=checksquare(board, i1, i2);
        
        i1=3; i2=3;
        bool sq5=checksquare(board, i1, i2);
        
        i1=3; i2=6;
        bool sq6=checksquare(board, i1, i2);
        
        i1=6; i2=0;
        bool sq7=checksquare(board, i1, i2);
        
        i1=6; i2=3;
        bool sq8=checksquare(board, i1, i2);
        
        i1=6; i2=6;
        bool sq9=checksquare(board, i1, i2);
        
        return sq1 && sq2 && sq3 && sq4 && sq5 && sq6 && sq7 && sq8 && sq9;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        return checkrows(board) && checkcols(board) && checksquares(board);
    }
};
