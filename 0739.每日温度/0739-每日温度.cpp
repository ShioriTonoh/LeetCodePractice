class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), -1);
        stack<int> increasingStack;

        for(int i=temperatures.size()-1; i>=0; --i)
        {
            while(!increasingStack.empty() && temperatures[i] >= temperatures[increasingStack.top()])
            {
                increasingStack.pop();
            }
            result[i]=increasingStack.empty()?0:(increasingStack.top()-i);
            increasingStack.push(i);
        }

        return result;
    }
};