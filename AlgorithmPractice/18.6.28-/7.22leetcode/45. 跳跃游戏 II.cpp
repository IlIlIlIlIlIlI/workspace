class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int bound = 0;
        int new_bound = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > bound) {
                bound = new_bound;
                ++step;
            }
            new_bound = max(new_bound, i + nums[i]);
        }
        return step;
    }
};





class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0, n = nums.size(), i = 0, cur = 0;
        while (cur < n - 1) {
            ++res;
            int pre = cur;
            for (; i <= pre; ++i) {
                cur = max(cur, i + nums[i]);
            }
            if (pre == cur) return -1;
        }
        return res;
    }
};










static int x = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();

class Solution {
public:
	int jump(std::vector<int>& A) {
        size_t n = A.size();
		int *min = (int*)malloc(sizeof(int)*n);
		int cur = 1;
		int result;
		memset(min, 0, sizeof(int)*n);
		for (int i = 0; i < n; i++)
		{
			while (cur < n && cur - i <= A[i])
			{
				min[cur++] = min[i] + 1;
			}
		}
		result = min[n - 1];
		free(min);
		return result;
	}
};





public class Solution {
    public int jump(int[] nums) {
    	/**
    	 * 本题用贪心法求解，
    	 * 贪心策略是在每一步可走步长内，走最大前进的步数
    	 */
        if(nums.length <= 1){
            return 0;
        }
        int index,max = 0;
        int step = 0,i= 0;
        while(i < nums.length){
        	//如果能直接一步走到最后，直接步数+1结束
            if(i + nums[i] >= nums.length - 1){
            	step++;
            	break;
            }
            max = 0;//每次都要初始化
            index = i+1;//记录索引，最少前进1步
            for(int j = i+1; j-i <= nums[i];j++){//搜索最大步长内行走最远的那步
                if(max < nums[j] + j-i){
                    max = nums[j] + j-i;//记录最大值
                    index = j;//记录最大值索引
                }
            }
            i = index;//直接走到能走最远的那步
            step++;//步长+1
        }
        return step;
    }
}





class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return 0;
        }
        int step = 0;
        int index = 0;
        int ending = nums.size()-1;
        int tmp = 0;
        while(tmp <= ending)
        {
            if(tmp + nums[tmp] >= ending)
            {
                return step+1;
            }
            int maxn = -1;
            for(int i = tmp+1;i<tmp+nums[tmp];i++)
            {
                if(maxn < i + nums[i])
                {
                    maxn = i + nums[i];
                    index = i;
                }
            }
            step++;
            tmp = index;
        }
        return step;
    }
};
