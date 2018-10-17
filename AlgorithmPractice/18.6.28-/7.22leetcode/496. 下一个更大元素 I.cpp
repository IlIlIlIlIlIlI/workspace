/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find(int x,int *nums,int numsize)
{
    int i,f=0;
    for(i=0;i<numsize;i++)
    {
        if(nums[i]==x)
            f=1;
        if(f&&nums[i]>x)
            return nums[i];
    }
    return -1;
}

int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize)
{
    int *ans,i,l=0;
    ans=(int *)malloc(sizeof(int)*1000);
    for(i=0;i<findNumsSize;i++)
        ans[l++]=find(findNums[i],nums,numsSize);
    *returnSize=findNumsSize;
    return ans;
}




/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include <cstdio>
 #include <cstdlib>
 #include <algorithm>
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    sort(nums,nums+numsSize);
    for(int i = 0;i<findNumsSize;i++)
    {
        int l = 0,r = numsSize-1,mid;
        while(r > l)
        {
            mid = (l+r)/2;
            if(nums[mid] > findNums[i])
            {
                r = mid-1;
            }
            else if((nums[mid] == findNums[i]))
            {
                if(mid == numsSize-1)
                {
                    findNums[i] = -1;
                    break;
                }
                else
                {
                    findNums[i] = nums[mid+1];
                    break;
                }
            }
            else if(nums[mid] < findNums[i])
            {
                l = mid+1;
            }
        }
        if(r == l)
        {
            if(nums[mid] != findNums[i])
            {
                findNums[i] = -1;
            }
            else
            {
                if(l == numsSize-1)
                {
                    findNums[i] = -1;
                }
                else
                {
                    findNums[i] = nums[l+1];
                }
            }
        }
    }
    return findNums;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    *returnSize = findNumsSize;
    int *ans = (int*)malloc(sizeof(int)*findNumsSize);
    for(int i = 0;i<findNumsSize;i++)
    {
        int j,k;
        for(j = 0;j<numsSize;j++)
        {
            if(findNums[i] == nums[j])
            {
                k = j;
                break;
            }
        }
        if(j == numsSize-1)
            {
                ans[i] = -1;
                continue;
            }
        for(j = k+1;j<numsSize;j++)
        {

            if(nums[k] < nums[j])
            {
                ans[i] = nums[j];
                break;
            }
            if(j == numsSize-1)
            {
                ans[i] = -1;
                break;
            }
        }
    }
    return ans;
}
