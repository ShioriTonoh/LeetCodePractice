class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>{searchLeftBound(nums, target), searchRightBound(nums, target)};
    }

    int searchLeftBound(vector<int>& nums, int target){
        if(nums.size() > 1)
        {
            int left =0, right = nums.size(), mid = 0;
            while(left<right)
            {
                mid = left+(right-left)/2;
                cout<<mid<<"left"<<endl;

                if(target == nums[mid])
                {
                    right = mid;
                }
                else if(target < nums[mid])
                {
                    right = mid;
                }
                else if(target > nums[mid])
                {
                    left = mid+1;
                }
            }

            if(right < nums.size() && target == nums[right])
            {
                return right;
            }
        }
        else if(nums.size() == 1 && nums[0] == target)
        {
            return 0;
        }

        return -1;
    }

    int searchRightBound(vector<int>& nums, int target){
        if(nums.size() > 1)
        {
            int left =0, right = nums.size(), mid = 0;

            while(left<right)
            {
                mid = left+(right-left)/2;
                cout<<mid<<"right"<<endl;

                if(target == nums[mid])
                {
                    left = mid+1;
                }
                else if(target < nums[mid])
                {
                    right = mid;
                }
                else if(target > nums[mid])
                {
                    left = mid+1;
                }
            }

            if((left-1) < nums.size() && target == nums[left-1])
            {
                return left-1;
            }
        }
        else if(nums.size() == 1 && nums[0] == target)
        {
            return 0;
        }

        return -1;
    }
};