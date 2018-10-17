static auto x = []() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	return 0;
}();

//先排序 然后遍历指定最长边
//之后在左边区间 left right
//如果两个满足 那么left一直移动到right-1肯定都满足 然后right--
//如果不满足 那么试一试left++
//牛逼啊！


class Solution {
public:
	int triangleNumber(vector<int>& nums) {
		if (nums.size() < 3) return 0;
		sort(nums.begin(), nums.end());

		int answer = 0;

		for (int i = nums.size() - 1; i >= 2; --i)
		{
			int left = 0;
			int right = i - 1;
			while (left < right)
			{
				if (nums[left] + nums[right] > nums[i])
				{
					answer += right - left;
					right--;
				}
				else
				{
					left++;
				}
			}
		}
		return answer;
	}
};



public:
    int triangleNumber(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int count = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < n - 1; ++j) {
                int k = BinarySearch(nums, j + 1, nums[i] + nums[j]);
                count += k - (j + 1);
            }
        }
        return count;
    }
    //搜索小于val的数的位置
    int BinarySearch(vector<int>& nums, int start, int val) {
        int end = static_cast<int>(nums.size()) - 1;
        while (start <= end) {
            int mid = (start + end) >> 1;
            if (nums[mid] >= val) end = mid - 1;
            else start = mid + 1;
        }
        return start;
    }
};



class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j<nums.size(); j++)
        for(int k = j + 1; k < nums.size(); k++){
            if((nums[i] + nums[j] > nums[k]) && (nums[k] + nums[j] > nums[i]) && (nums[k] + nums[i] > nums[j]))
                count++;
        }
        return count;
    }
};
