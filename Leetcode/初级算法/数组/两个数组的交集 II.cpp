class Solution {    //排序后题目
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        int n1 = nums1.size(), n2 = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for(int i = 0, j = 0; i < n1 && j < n2; )
        {
            if(nums1[i] == nums2[j])
            {
                vec.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums1[i] > nums2[j])
            {
                j++;
            }
        }
    return vec;
    }
};


class Solution {    //原始题目
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> vec;
        for(int i = 0; i < n1; i++)
        {
            int cnt = 0;
            for(int j = 0; j < n2; j++)
            {
                if(nums2[j] == nums1[i] && !cnt)
                {
                    vec.push_back(nums2[j]);
                    nums2[j] = 0xffffff;
                    cnt++;
                }
            }
        }
        return vec;
    }
};