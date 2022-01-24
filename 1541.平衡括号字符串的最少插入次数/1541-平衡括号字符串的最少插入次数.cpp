class Solution {
public:
    int minInsertions(string s) {
        int leftBuffer = 0, pendingInsert = 0;
        for(int i=0;i<s.length();++i)
        {
            if (s[i] == '(')
            {
                ++leftBuffer;
            }
            else
            {
                if (leftBuffer > 0)
                {
                    --leftBuffer;
                }
                else
                {
                    ++pendingInsert;
                }
                if (i + 1 < s.length() && s[i+1] == ')')
                {
                    ++i;
                }
                else
                {
                    ++pendingInsert;
                }
            }
        }
        return pendingInsert + 2 * leftBuffer;
    }
};