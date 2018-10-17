static const auto speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
        {
            return nums.size();
        }
        int i = 0, j = 0;
        for(; i <nums.size(); i++)
        {
            if(nums[j] != nums[i])
            {
                nums[++j] = nums[i];
            }
        }
        return j+1;
    }
};