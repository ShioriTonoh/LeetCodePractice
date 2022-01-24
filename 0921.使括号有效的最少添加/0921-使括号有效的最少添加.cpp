class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftBuffer=0, pendingAdd=0;
        for(char &c: s)
        {
            if(c == '(')
            {
                ++leftBuffer;
            }
            else
            {
                if(leftBuffer > 0) --leftBuffer;
                else ++pendingAdd;
            }
        }
        return pendingAdd+leftBuffer;
    }
};