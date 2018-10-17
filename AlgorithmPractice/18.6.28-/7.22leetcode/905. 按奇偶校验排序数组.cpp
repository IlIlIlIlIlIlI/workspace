class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> a,b;
        for(int i = 0; i < A.size()-1; i++)
        {
            if(A[i] % 2 == 0)
            {
                a.push_back(A[i]);
            }
            else
            {
                b.push_back(A[i]);
            }
        }
        for(int i = 0; i < b.size(); i++)
        {
            a.push_back(b[i]);
        }
        return a;
    }
};
