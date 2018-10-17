class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() == 0 || A.size() == 1)
        {
            return true;
        }

        int f = 0;
        if(A[0] > A[1])
        {
            f = 1;
        }
        else if(A[0] == A[1])
        {
            for(int i = 0,j = 1; j < A.size(); i++,j++)
            {
                if(A[i] != A[j])
                {
                    if(A[i] > A[j])
                    {
                        f = 1;
                    }
                }
            }
        }

        int b = 0;
        if(f == 0)
        {
            for(int i = 0,j = 1; j < A.size(); i++,j++)
            {
                if(A[i] > A[j])
                {
                    b = 1;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0,j = 1; j < A.size(); i++,j++)
            {
                if(A[i] < A[j])
                {
                    b = 1;
                    break;
                }
            }
        }

        if(b == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};
/*[1,2,2,3]*/
