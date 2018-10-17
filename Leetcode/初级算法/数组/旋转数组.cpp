class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.begin() + nums.size() - k);
        reverse(nums.begin() + nums.size() - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k%n;
        nums.insert(nums.end(),nums.begin(),nums.end()-k);
        nums.erase(nums.begin(),nums.begin()+n-k);
    }
};        
        
        class Solution {
        public:
            void rotate(vector<int>& nums, int k) {
                int vec[nums.size()];
                for(int i = 0; i < nums.size(); i++)
                {
                    int index = (i+k)%nums.size();
                    vec[index] = nums[i];
                }
                for(int i = 0; i < nums.size(); i++)
                {
                    nums[i] = vec[i];
                }
            }
        };