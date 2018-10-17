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
    	 * ������̰�ķ���⣬
    	 * ̰�Ĳ�������ÿһ�����߲����ڣ������ǰ���Ĳ���
    	 */
        if(nums.length <= 1){
            return 0;
        }
        int index,max = 0;
        int step = 0,i= 0;
        while(i < nums.length){
        	//�����ֱ��һ���ߵ����ֱ�Ӳ���+1����
            if(i + nums[i] >= nums.length - 1){
            	step++;
            	break;
            }
            max = 0;//ÿ�ζ�Ҫ��ʼ��
            index = i+1;//��¼����������ǰ��1��
            for(int j = i+1; j-i <= nums[i];j++){//������󲽳���������Զ���ǲ�
                if(max < nums[j] + j-i){
                    max = nums[j] + j-i;//��¼���ֵ
                    index = j;//��¼���ֵ����
                }
            }
            i = index;//ֱ���ߵ�������Զ���ǲ�
            step++;//����+1
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
