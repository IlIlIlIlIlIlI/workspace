class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2){
            if(nums[i] != nums[i+1]) return nums[i];
        }
        return nums.back();
    }
};




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=1;i<nums.size();i++){
            nums[0] ^= nums[i];
        }
        return nums[0];
    }
};

static const auto io_speed_up = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();




class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return nums[0];
        }
        sort(nums.begin(), nums.end());
        return nums[helper(nums, 0, nums.size()-1)];
    }

private:
    int helper(vector<int>& vec, int l, int r)
    {
        if(r-l == 0)
        {
            return r;
        }
        else if(r-l == 1)
        {
            return -1;
        }
        if(r-l > 1)
        {
            int mid = (l+r)/2;
            if(vec[mid] != vec[mid-1] && vec[mid] != vec[mid+1])
            {
                return mid;
            }
            else if(vec[mid] == vec[mid-1])
            {
                return (helper(vec, l, mid) > helper(vec, mid+1, r)) ? helper(vec, l, mid) : helper(vec, mid+1, r);
            }
            else if(vec[mid] == vec[mid+1])
            {
                return (helper(vec, l, mid-1) > helper(vec, mid, r)) ? helper(vec, l, mid-1) : helper(vec, mid, r);
            }
        }
        
    }
};