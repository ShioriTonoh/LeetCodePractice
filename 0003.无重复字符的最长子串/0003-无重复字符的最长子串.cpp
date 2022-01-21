#include<algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> inWindow;
        int left=0, right=0;
        int maxLength=0;

        for(char &c: s)
        {
            ++right;
            ++inWindow[c];

            while(inWindow[c]>1)
            {
                --inWindow[s[left]];
                ++left;
            }
            maxLength = max(right-left,maxLength);
        }

        return maxLength;
    }
};