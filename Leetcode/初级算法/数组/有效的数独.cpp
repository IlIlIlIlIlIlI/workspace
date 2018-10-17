class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9] = {0}, col[9][9] = {0}, grid[9][9] = {0};
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    int k = i / 3 * 3 + j / 3;
                    if (row[i][num] || col[j][num] || grid[k][num]) return false;
                    row[i][num] = col[j][num] = grid[k][num] = 1;
                }
            }
        }
        return true;
    }
};




class Solution {    //错误
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                int cnt = 0;
                for(int x = 3*i; x < x+3; x++)
                {
                    for(int y = 3*j; y < y+3; y++)
                    {
                        if(board[x][y] != '.' && 
                           board[x][y] >= '1' && board[x][y] <= '9')
                        {
                            cnt++;
                            cout << board[x][y] << endl;
                        }
                        if(cnt > 9)
                        {
                            return false;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < 9; i++)
        {
            int cnt1 = 0, cnt2 = 0;
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.' && 
                   board[i][j] >= '1' && board[i][j] <= '9')
                {
                    cnt1++;
                }
                if(board[i][j] != '.' && 
                   board[j][i] >= '1' && board[j][i] <= '9')
                {
                    cnt2++;
                }
                if(cnt1 > 9 || cnt2 > 9)
                {
                    return false;
                }
            }
        }
        return true;
    }
};