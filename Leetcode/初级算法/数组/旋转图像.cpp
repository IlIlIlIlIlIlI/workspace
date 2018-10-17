class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //转置
        int len = matrix.size();
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = i+1; j < len; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //对称
        for (size_t i = 0; i < len; i++)
        {
            for (size_t j = 0; j < len / 2; j++)
            {
                swap(matrix[i][j], matrix[i][len-j-1]);
            }
        }
    }
};



class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        //int m = matrix.size();
        //if(m != n) return;
        
        for(int i = 0; i < n/2; i++)
        {
            swap(matrix[i], matrix[n-i-1]);
        }

        for(int i = 0; i < n; i++)  //转置
        {
            for(int j = i+1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};