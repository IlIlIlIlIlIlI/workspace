class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        set<int> m{-1, n};
        multimap<int, int> idx;
        for (int i = 0; i < n; ++i) idx.emplace(A[i], i);
        int res = 0;
        for (auto &p : idx) {
            auto pos = m.insert(p.second);
            auto lp = prev(pos.first), rp = next(pos.first);
            int left = p.second - *lp;
            int right = *rp - p.second;
            res += p.first * left * right;
            res %= 1000000007;
        }
        return res;
    }
};








class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        std::vector<int> smallerIndexes { -1 }, sums(A.size(), 0);
        for(int i = 0; i < A.size(); i++) {
            while(smallerIndexes.size() > 1 && A[smallerIndexes.back()] > A[i])
                smallerIndexes.pop_back();
            sums[i] = A[i] * (i - smallerIndexes.back()) + (smallerIndexes.size() > 1 ? sums[smallerIndexes.back()] : 0);
            smallerIndexes.push_back(i);
        }
        int result = 0;
        for(const auto n: sums)
            result = (result + n) % (1000000000 + 7);
        return result;
    }
};






class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        for(int i = 0; i < A.size(); ans = (ans + helper(A, i) * A[i]) % MOD, i++);
        return ans;
    }
private:
    int helper(vector<int>& A, int i)
    {
        int l = 1, r = 1;
        for(int j = i - 1; j >= 0 && A[j] > A[i]; l++, j--);
        for(int j = i + 1; j < A.size() && A[j] >= A[i]; r++, j++);
        return l*r;
    }
};







class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0;
        for(int i = 0; i < A.size(); i++)
        {
            int index = least(A, i);
            for(int j = i; j < A.size(); j++)
            {
                int m = -1;
                if((A[i] == A[index]) || (j >= index))
                {
                    m = A[index];
                }
                else
                {
                    m = helper(A, i, j);
                }
                ans  = (ans + m) % (int)(1e9 + 7.0);
            }
        }
        return ans;
    }
private:
    int helper(vector<int>& a, int i, int j)
    {
        int m = a[i];
        for(int k = i; k <= j; k++)
        {
            m = (m < a[k]) ? m : a[k];
        }
        return m;
    }
private:
    int least(vector<int>& a, int j)
    {
        int mi = a[j];
        int index = j;
        for(int i = j; i < a.size(); i++)
        {
            if(mi > a[i])
            {
                mi = a[i];
                index = i;
            }
        }
        return index;
    }
};
