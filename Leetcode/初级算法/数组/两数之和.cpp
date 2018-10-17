class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        unordered_map<int, int> has;
        vector<int> res;
        
        for(int i=0; i<nums.size();i++){
            int fin = target - nums[i];
            if(has.find(fin)!=has.end()){
                res.push_back(has[fin]);
                res.push_back(i);
                return res;
            }
            has[nums[i]]=i;
        }
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::pair<int, int> result;
        
        vector<int> origin = nums;
        sort(nums.begin(), nums.end());
        
        for (vector<int>::iterator it = nums.begin();
            it != nums.end(); it++) {
            
            int real_target = target - *it;
            vector<int>::iterator res = lower_bound(nums.begin(), nums.end(), 
                                                    real_target);
            
            if (res != nums.end() && *res == real_target && res != it) {
                result = std::make_pair(*it, *res);
            }
        }
                
        std::vector<int> ret(2, -1);
        
        for (size_t i = 0; i != nums.size(); i++) {
            if (ret[0] == -1 && origin[i] == result.first) {
                ret[0] = i;
            }
            if (ret[1] == -1 && origin[i] == result.second && i != ret[0]) {
                ret[1] = i;
            }
            if (ret[1] >= 0 && ret[0] >= 0) {
                break;
            }
        }
        
        return ret;
    }
};



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vec;
        for(int i = 0; i < nums.size(); i++)
        {
                for(int j = i+1; j < nums.size(); j++)
                {
                    if(nums[i] + nums[j] == target)
                    {
                        vec.push_back(i);
                        vec.push_back(j);
                    }
                }
        }
        return vec;
    }
};