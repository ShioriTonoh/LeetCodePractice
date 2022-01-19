class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> inTarget, inWindow;
        for(char &c: s1) ++inTarget[c];

        int left=0, right=0;
        int valid=0;

        while(right < s2.length())
        {
            char pendingInsert = s2[right];
            ++right;
            
            if(inTarget.count(pendingInsert))
            {
                ++inWindow[pendingInsert];
                if(inWindow[pendingInsert] == inTarget[pendingInsert]) ++valid;
            }

            while(right-left >= s1.length())
            {
                if(valid == inTarget.size()) return true;
                char pendingDelete = s2[left];
                ++left;
                if(inTarget.count(pendingDelete))
                {
                    if(inWindow[pendingDelete] == inTarget[pendingDelete]) --valid;
                    --inWindow[pendingDelete];
                }
            }
        }

        return false;
    }
};