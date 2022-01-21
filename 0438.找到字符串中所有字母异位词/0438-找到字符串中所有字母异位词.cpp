class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> inTarget, inWindow;
        vector<int> startPosVec;
        for(char &c : p) ++inTarget[c];

        int left=0, right=0;
        int valid=0;
        while(right<s.length())
        {
            const char &pendingInsert=s[right];
            ++right;

            if(inTarget.count(pendingInsert))
            {
                ++inWindow[pendingInsert];
                if(inTarget[pendingInsert] == inWindow[pendingInsert]) ++valid;
            }

            while(valid == inTarget.size())
            {
                if(right-left == p.length())
                {
                    startPosVec.push_back(left);
                }

                const char& pendingDelete=s[left];
                ++left;

                if(inTarget.count(pendingDelete))
                {
                    if(inWindow[pendingDelete] == inTarget[pendingDelete]) --valid;
                    --inWindow[pendingDelete];
                }
            }
        }

        return startPosVec;
    }
};