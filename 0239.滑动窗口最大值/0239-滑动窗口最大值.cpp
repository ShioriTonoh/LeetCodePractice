class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        vector<int> result;

        for(int i=0;i<nums.size();++i)
        {
            while(!window.empty() && window.back() < nums[i])
            {
                window.pop_back();
            }
            window.push_back(nums[i]);

            if(i>=k-1)
            {
                result.push_back(window.front());
                if(window.front() == nums[i-k+1])
                {
                    window.pop_front();
                }
            }
        }

        return result;
    }
};