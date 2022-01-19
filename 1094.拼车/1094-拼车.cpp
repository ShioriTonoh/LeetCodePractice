class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> delta(1001,0);
        for(auto &trip:trips)
        {
            delta[trip[1]]+=trip[0];
            delta[trip[2]]-=trip[0];
        }

        if(delta[0]>capacity)
        {
            return false;
        }
        
        for(int i=1;i<delta.size();++i)
        {
            delta[i]+=delta[i-1];
            if(delta[i]>capacity) 
            {
                return false;
            }
        }

        return true;
    }
};