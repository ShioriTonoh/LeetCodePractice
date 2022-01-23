class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        for(int &n: nums)
        {
            if(n)
            {
                swap(nums[slow],n);
                ++slow;
            }
        }
    }
};