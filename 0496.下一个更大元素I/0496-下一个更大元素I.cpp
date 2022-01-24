class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> increasingStack;
        unordered_map<int, int> valueToGreater;
        for(int i=nums2.size()-1;i>=0;--i)
        {
            while(!increasingStack.empty() && nums2[i]>=increasingStack.top())
            {
                increasingStack.pop();
            }
            valueToGreater[nums2[i]]=increasingStack.empty()?-1:increasingStack.top();
            increasingStack.push(nums2[i]);
        }

        vector<int> result;
        for(int &n: nums1)
        {
            result.push_back(valueToGreater[n]);
        }
        return result;
    }
};