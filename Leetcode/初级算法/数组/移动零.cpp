class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i <nums.size(); i++)
        {
            nums[i-sum] = nums[i];
            if(nums[i] == 0)
            {
                sum++;
            }
        }
        for(int i = 0; i < sum; i++)
        {
            nums[nums.size()-1-i] = 0;
        }
    }
};