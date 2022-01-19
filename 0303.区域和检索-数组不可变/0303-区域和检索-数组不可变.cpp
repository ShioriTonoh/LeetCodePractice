class NumArray {
public:
    NumArray(vector<int>& nums) {
        int inputSize=nums.size();
        preCalSum.resize(inputSize+1);
        if(!nums.empty())
        {
            for(int i=1;i<=inputSize;++i)
            {
                preCalSum[i]=preCalSum[i-1]+nums[i-1];
            }
        }       
    }
    
    int sumRange(int left, int right) {
        if(right>=left && left>=0)
        {
            return preCalSum[right+1]-preCalSum[left];
        }
        return 0;

    }

private:
    vector<int> preCalSum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */