class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                //visit�����¼�������Ƿ񱻷��ʹ�
                vector<vector<bool>> visit(row, vector<bool>(col, false));
                bool res = dfs(board, visit, i, j, word, 0);
                if (res == true)
                    return true;
            }
        }
        return false;
    }
    //index��ʾ���ǵ�ǰ̽�����ǵڼ�����
    bool dfs(vector<vector<char>>& b, vector<vector<bool>>& visit, int x, int y,                //���������ÿһ��
        string s, int index)
    {
        int row = b.size();
        int col = b[0].size();
        if (index == s.length())
            return true;
        //���¼������ ���ٽ��д���
        //1������Խ��
        //2���ýڵ��Ѿ����ʹ�
        //3��indexλ�õ��ַ����ַ����е��ַ�����
        else if (x < 0 || x >= row || y < 0 || y >= col   //1
                 || visit[x][y] == true                   //2
                 || s[index]!=b[x][y])                    //3
            return false;
        else
        {
            visit[x][y] = true;
            //��xy��������Χ����̽��
            bool x_1y = dfs(b, visit, x - 1, y, s, index + 1);
            bool x1y = dfs(b, visit, x + 1, y, s, index + 1);
            bool xy_1 = dfs(b, visit, x, y - 1, s, index + 1);
            bool xy1 = dfs(b, visit, x, y + 1, s, index + 1);

            if (x_1y || x1y || xy_1 || xy1)
                return true;
            else
            {
                visit[x][y] = false;
                return false;
            }
        }
    }
};







class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

    }
};

