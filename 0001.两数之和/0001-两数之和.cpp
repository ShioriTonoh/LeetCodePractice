class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;
        for(int i=0; i<nums.size(); ++i)
        {
            auto result = hashmap.find(target-nums[i]);
            if(result != hashmap.end()) return {i, result->second};
            hashmap.insert({nums[i], i});
        }
        return {};
    }
};