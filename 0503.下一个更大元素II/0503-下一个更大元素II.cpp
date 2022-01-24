class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int originSize=nums.size();
        vector<int> result(originSize,-1);
        stack<int> increasingStack;

        for(int i=2*nums.size()-1;i>=0;--i)
        {
            while(!increasingStack.empty() && nums[i%originSize]>=increasingStack.top())
            {
                increasingStack.pop();
            }
            result[i%originSize]=increasingStack.empty()?-1:increasingStack.top();
            increasingStack.push(nums[i%originSize]);
        }

        return result;
    }
};