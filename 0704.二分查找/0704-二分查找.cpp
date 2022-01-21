class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1) return -1;
        int left = 0, right = nums.size();

        while(left<right)
        {
            int mid = (left+right)/2;
            if(target == nums[mid]) 
                return mid;
            else if(target < nums[mid])
            {
                right = mid;
            }
            else if(target > nums[mid])
            {
                left = mid+1;
            }

        }

        return -1;
    }
};