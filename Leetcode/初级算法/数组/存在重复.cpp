 static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1])
                return true;
        }
        return false;


    }
};



static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       for (int i = 1; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    break;
                } else if (nums[i] == nums[j]) {
                    return true;
                }
            }

        }
        return false;


    }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
        {
            return false;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0, j = 1; i < nums.size(); i++)
        {
            if(nums[i] == nums[j])
            {
                return true;
            }
            else if(nums[i] != nums[j])
            {
                j++;
            }
        }
        return false;
    }
};