
/*!
本题其实是构造卡特兰数的应用，采用动态规划思想求解。对于n个结点，除去根节点，还剩余n-1个结点，因此左右子树的结点数分配方式如下所示：

(0,n-1), (1,n-2), (2, n-3), ....(n-1,0)

我们可以简单的得到：

n=0时，种类数为dp(n)=1；
n=1时，种类数为dp(n)=1；
则可以依次计算得到n个结点时二叉树的种类，即：

dp(n)=dp(0)*dp(n-1)+dp(1)*dp(n-2)+dp(2)*dp(n-3)+...+dp(n-1)*dp(0)

另外也可以直接构造卡特兰数公式求解：

dp(n)=C(2n,n)/(n+1)
*/
class Solution {
public:
int numTrees(int n) {
        vector<int> vec(n+1, 0);
        vec[0] = 1;
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                vec[i] += vec[j] * vec[i-j-1];
            }
        }
        return vec[n];
    }
};
