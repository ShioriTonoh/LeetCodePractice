class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int slow=0;
        for(int &n: nums)
        {
            if(n != val)
            {
                nums[slow] = n;
                ++slow;
            }
        }
        return slow;
    }
};