class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> inTarget,inWindow;
        // fill in the pair with char and times it appeared
        for(char &c:t) ++inTarget[c];

        int left=0, right=0; // the window is [left, right)
        int valid=0; // record how many chars have been included in currrent window
        int start=0, length=INT_MAX; // record the temp string position 
        int strLength=s.length(); // record the original string length
        while(right < strLength)
        {
            char pendingInsert=s[right]; // get the new char
            ++right; // slice the window
            // check if the new char is needed in the target string
            if(inTarget.count(pendingInsert)) // map.count(c) returns 1 if key c exist in unordered_map
            {
                ++inWindow[pendingInsert];
                // check if pendingInsert is included enough in the window
                if(inWindow[pendingInsert] == inTarget[pendingInsert]) ++valid;

                while(valid == inTarget.size()) // while all chars have been in the window
                {
                    if(right - left < length) // if the current min string is shorter than the former one
                    {
                        //record the current minimal string
                        start = left;
                        length = right - left; 
                    }

                    char pendingDelete=s[left];
                    ++left;

                    if(inTarget.count(pendingDelete))
                    {
                        // the valid chars will not match the target size
                        if(inWindow[pendingDelete] == inTarget[pendingDelete]) --valid;
                        --inWindow[pendingDelete];
                    }
                }
            }
        }

        return length == INT_MAX?"":s.substr(start,length);
    }
};